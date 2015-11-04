#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 10

struct TipoArgumento{
    int valor;
};

void *pinta(void *arg){
    struct TipoArgumento *p = (struct TipoArgumento *) arg;
    int valor = p->valor;
    int suma = 0;

    for(int i=0; i<1000; i++)
	printf("%i", valor);

    return NULL;
}

int main(int argc, char *argv[]){

    struct TipoArgumento parametro;
    pthread_t hilo_id[N];

    for (int i=0; i<N; i++){
	parametro.valor = i;
	pthread_create(&hilo_id[i], NULL, pinta, &parametro);
    }

    printf("Hola\n");

    for (int i=0; i<N; i++)
        pthread_join(hilo_id[i], NULL);

    return EXIT_SUCCESS;
}
