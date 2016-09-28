#include "vectores.h"


int *suma(int resultado[DIM], int op1[DIM], int op2[DIM]) {

    for (int i=0; i<DIM; i++)
        resultado[i] = op1[i] + op2[i];


    return (int *) resultado;
}


