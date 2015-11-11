#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define NPEONES  4
#define NALBA    1140
#define ALBACONC 1000
#define TOTAL 4000


int puestos = 0;
int pila = 150;

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

int quitar(int cantidad) {
    if (cantidad > pila)
        cantidad = pila;


    pthread_mutex_lock(&mutex_pila);
    pila -= cantidad;
    pthread_mutex_unlock(&mutex_pila);

    return cantidad;
}

void cuenta_ladrillos(){
    printf("[%i]\t", get_ladrillos());
}

void *peon(void *p) {
    const char * mi_nombre = (const char *) p;
    int ladrillos;

    while(1){
        ladrillos = rand() % 10 + 10;

        cuenta_ladrillos();
        printf("%s: Pongo %i ladrillos-\n",
                mi_nombre, ladrillos);
        poner(ladrillos);
        usleep(100000 * (rand() % 3 + 1) );
    }
}

void *albannil(void *n) {
    int ladrillos;
    int *mn = (int *) n;
    int mi_nombre = *mn;
    int cogidos = 0;

    while(puestos < TOTAL) {
        sem_wait(&albaforo);
        ladrillos = rand() % 2 + 1;
        cuenta_ladrillos();
        printf("%i:\tQuiero %i ladrillos.\tCojo %i\n",
                mi_nombre, ladrillos, cogidos = quitar(ladrillos));
        usleep(100000 * (rand() % 3 + 1) );
        sem_post(&albaforo);

        pthread_mutex_lock(&mutex_edif);
        puestos += cogidos;
        usleep(10000 * (rand() % 3 + 1) );
        pthread_mutex_unlock(&mutex_edif);
    }
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
