#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t espera;

void *libre(void *nada) {

    sem_wait(&espera);
    printf("\nAhora ya podemos usar puertos\n");

    return NULL;
}

void *cuenta(void *nada){
    for (int i=0; i<200; i++){
        printf("%i ", i);
        usleep(1000);
        if (i==124)
            sem_post(&espera);
    }

    return NULL;
}

int main(int argc, char *argv[]) {

    pthread_t primero, segundo;

    sem_init(&espera, 0, 0);

    pthread_create(&primero, NULL, &cuenta, NULL);
    pthread_create(&segundo, NULL, &libre, NULL);

    pthread_join(primero, NULL);
    pthread_join(segundo, NULL);

    printf("\n");

    sem_destroy(&espera);

    return EXIT_SUCCESS;
}

