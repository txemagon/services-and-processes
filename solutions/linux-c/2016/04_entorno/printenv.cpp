#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main() {

    char **entorno;

    for (entorno=environ; *entorno!=NULL; entorno++)
        printf(" %s\n", *entorno);

    return EXIT_SUCCESS;
}

