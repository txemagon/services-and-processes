#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    /* Un programa */
    pid_t child = fork();
    /* Dos Programas */
    if (child){
	/* Luke. Soy tu padre. */
	printf("Soy el padre.\n");
    } else {
	/* Te vi en el bosque de Endor */
	printf("Soy el hijo.\n");
	execlp("firefox", "firefox", NULL);
    }

    return EXIT_SUCCESS;
}

