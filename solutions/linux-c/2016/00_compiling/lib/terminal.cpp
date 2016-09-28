#include <stdio.h>
#include <stdlib.h>

#include "terminal.h"


void preguntar(int vector[DIM]) {

    printf("Vector con %i coordenadas: \n", DIM);

    for (int i=0; i<DIM; i++){
        printf(" | ");
        scanf(" %i", &vector[i]);
    }
    printf(" |\n");
}


void imprimir(int vector[DIM]) {
    for (int i=0; i<DIM; i++)
        printf(" | %i", vector[i]);

    printf(" |\n");
}
