#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define NPEONES  2
#define NALBA    140
#define ALBACONC 10
#define TOTAL 4000


int puestos = 0; // Ladrillos ya puestos
int pila = 150;  // Ladrillos disponibles.

pthread_mutex_t mutex_pila = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_edif = PTHREAD_MUTEX_INITIALIZER;
sem_t albaforo;

void poner(int cantidad) {
    pthread_mutex_lock(&mutex_pila);
        pila += cantidad;
    pthread_mutex_unlock(&mutex_pila);
}

int get_ladrillos() {
    int ladrillos;


    pthread_mutex_lock(&mutex_pila);
    ladrillos = pila;
    pthread_mutex_unlock(&mutex_pila);

    return ladrillos;
}

int get_puestos() {
    int res;
    pthread_mutex_lock(&mutex_edif);
    res = puestos;
    pthread_mutex_unlock(&mutex_edif);
    return res;
}

int construye(int ladrillos) {
    int faltan = TOTAL - get_puestos();
    int devolver = 0;
    if (faltan > 0) {
        if (ladrillos > faltan){
            devolver  = ladrillos - faltan;
            ladrillos = faltan;
        }
        pthread_mutex_lock(&mutex_edif);
        puestos += ladrillos;
        pthread_mutex_unlock(&mutex_edif);
        usleep(10000 * (rand() % 3 + 1) );
    }
    return devolver;
}

int quitar(int cantidad) {
    if (cantidad > pila)
        cantidad = pila;


    pthread_mutex_lock(&mutex_pila);
    pila -= cantidad;
    pthread_mutex_unlock(&mutex_pila);

    usleep(100000 * (rand() % 3 + 1) );
    return cantidad;
}

void cuenta_ladrillos(){
    printf("Paponer:[%i] Puestos:[%i]\t",
            get_ladrillos(), get_puestos());
}

void *peon(void *p) {
    const char * mi_nombre = (const char *) p;
    int ladrillos;

    while(get_puestos() < TOTAL){
        ladrillos = rand() % 10 + 10;

        cuenta_ladrillos();
        printf("%s: Pongo %i ladrillos-\n",
                mi_nombre, ladrillos);
        poner(ladrillos);
        usleep(100000 * (rand() % 3 + 1) );
    }
    return NULL;
}

void *albannil(void *n) {
    int ladrillos;
    int *mn = (int *) n;
    int mi_nombre = *mn;
    int cogidos = 0;

    while(get_puestos() < TOTAL) {
        sem_wait(&albaforo);
          ladrillos = rand() % 10 + 1;
          cuenta_ladrillos();
          printf("%i:\tQuiero %i ladrillos.\tCojo %i\n",
                  mi_nombre, ladrillos, cogidos = quitar(ladrillos));
        sem_post(&albaforo);

        construye(cogidos);
    }
    return NULL;
}

int main() {

    pthread_t n_peon[NPEONES];
    const char *nombre_peon[NPEONES] = {
        "Jim",
        "Jack",
        "Joe",
        "James"
    };

    pthread_t n_alba[NALBA];
    int nombre_alba = 1;
    sem_init(&albaforo, 0, ALBACONC);

    for (int i=0; i<NPEONES; i++)
        pthread_create(&n_peon[i], NULL,
                &peon, (void *) nombre_peon[i]);

    for (int i=0; i<NALBA; i++, nombre_alba++)
        pthread_create(&n_alba[i], NULL,
                &albannil, (void *) &nombre_alba);


    for (int i=0; i<NALBA; i++)
        pthread_join(n_alba[i], NULL);

    for (int i=0; i<NPEONES; i++)
        pthread_join(n_peon[i], NULL);

    sem_destroy(&albaforo);

    return EXIT_SUCCESS;
}
