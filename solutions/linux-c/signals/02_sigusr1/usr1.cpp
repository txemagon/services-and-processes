#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

sig_atomic_t counter = 0;

void own_signal(int signal) {
    counter++;
    fprintf(stderr, "%i\n", counter);
}

int main(int argc, char *argv[]) {

    struct sigaction nuevo_gestor;
    nuevo_gestor.sa_handler = own_signal;

    sigaction(SIGUSR1, &nuevo_gestor, NULL);

    while(1);

   return EXIT_SUCCESS;
}
