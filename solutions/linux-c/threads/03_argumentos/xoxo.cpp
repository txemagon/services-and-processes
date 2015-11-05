#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

struct TDatos {
    char caracter;
};

sig_atomic_t finish = 0; //sig_atomic_t se usa cuando quiero decir que no me interrumpan cuando estoy escribiendo en la variable

/* Es lo que pasa cuando pulsamos ctrl+c */
void bye(int sig_num){
    finish = 1;
    printf("\n\n\n Byeeeeee! \n\n\n");
}

void *print(void *datos) {
    struct TDatos *dato = (struct TDatos *) datos;
    char c = dato->caracter;

    while (!finish)
        putc(c, stderr);

    return NULL;
}

int main(int argc, char *argv[]) {

    pthread_t hilo[2];
    struct TDatos x = {'x'};
    struct TDatos o = {'o'};

    struct sigaction sa; 
    sa.sa_handler = &bye; // Se establece que la función bye gestiona el ctrl+c
    sigaction(SIGINT, &sa, NULL);

    /* Creo el hilo */
    pthread_create(&hilo[0], NULL, &print, (void *) &x); // (void *) es un molde que convierte &x en la dirección de nada
    pthread_create(&hilo[1], NULL, &print, (void *) &o);

    /* Espero a que el hilo termine */
    for (int i=0; i<2; i++)
        pthread_join(hilo[i], NULL);

    return EXIT_SUCCESS;
}
