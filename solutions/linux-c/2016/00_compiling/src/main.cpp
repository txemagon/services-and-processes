#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "general.h"
#include "terminal.h"
#include "vectores.h"

int main(int argc, char *argv[]) {

    int vector1[DIM],
        vector2[DIM],
        resultado[DIM];

    preguntar(vector1);
    preguntar(vector2);
    imprimir(suma(resultado, vector1, vector2));

    return EXIT_SUCCESS;
}
