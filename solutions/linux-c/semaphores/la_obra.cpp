#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NPEONES 2

int pila = 150;

void poner(int cantidad) {
        pila += cantidad;
}

void *peon(void *p) {
    const char * mi_nombre = (const char *) p;
    int ladrillos;

    while(1){
        ladrillos = rand() % 10 + 10;

        printf("%s: Pongo %i ladrillos-\n",
                mi_nombre, ladrillos);
        poner(ladrillos);
    }
}

int main(int argc, char *argv[]) {

    pthread_t n_peon[NPEONES];
    const char *nombre_peon[NPEONES] = {
        "Jim",
        "Jack"
    };

    for (int i=0; i<NPEONES; i++)
        pthread_create(&n_peon[i], NULL,
                &peon, (void *) nombre_peon[i]);


    for (int i=0; i<NPEONES; i++)
        pthread_join(n_peon[i], NULL);

   return EXIT_SUCCESS;
}
