#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

struct TDatos {
    char caracter;
};

sig_atomic_t finish = 0;

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
    sa.sa_handler = &bye;
    sigaction(SIGINT, &sa, NULL);


    pthread_create(&hilo[0], NULL, &print, (void *) &x);
    pthread_create(&hilo[1], NULL, &print, (void *) &o);

    for (int i=0; i<2; i++)
        pthread_join(hilo[i], NULL);

    return EXIT_SUCCESS;
}
