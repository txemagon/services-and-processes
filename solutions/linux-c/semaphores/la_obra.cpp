#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NPEONES 2
#define NALBA   40

int pila = 150;

pthread_mutex_t mutex_pila = PTHREAD_MUTEX_INITIALIZER;

void poner(int cantidad) {
    pthread_mutex_lock(&mutex_pila);
        pila += cantidad;
    pthread_mutex_unlock(&mutex_pila);
}

int quitar(int cantidad) {
    if (cantidad > pila)
        cantidad = pila;
    pila -= cantidad;

    return cantidad;
}

void *peon(void *p) {
    const char * mi_nombre = (const char *) p;
    int ladrillos;

    while(1){
        ladrillos = rand() % 10 + 10;

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

    while(1) {
        ladrillos = rand() % 2 + 1;
        printf("%i: Quiero %i ladrillos. Cojo %i\n",
                mi_nombre, ladrillos, quitar(ladrillos));
        usleep(100000 * (rand() % 3 + 1) );
    }
}

int main() {

    pthread_t n_peon[NPEONES];
    const char *nombre_peon[NPEONES] = {
        "Jim",
        "Jack"
    };

    pthread_t n_alba[NALBA];
    int nombre_alba = 1;

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

   return EXIT_SUCCESS;
}
