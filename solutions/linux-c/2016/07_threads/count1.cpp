#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


struct Param {
    char caracter;
    int cantidad;
};

void *print(void *parameter) {
    struct Param *datos = (struct Param *) parameter;
    struct Param copia = *datos;
    // Esto esta mal porque es dependiente del planificador.

    for (int i=0; i<copia.cantidad; i++)
        fputc(copia.caracter, stderr);

    return NULL;
}


int main(){

    pthread_t thread_id1, thread_id2;
    struct Param x = {'x', 20000};

    pthread_create(&thread_id1, NULL, &print, &x);
    x.caracter = 'o';
    x.cantidad = 50000;
    pthread_create(&thread_id2, NULL, &print, &x);

    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);

    printf("\n");

   return EXIT_SUCCESS;
}

