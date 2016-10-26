#include <stdio.h>
#include <stdlib.h>

int suma(void *parametros){

    int *mi_parametro = (int *) parametros;

    return *mi_parametro + *(mi_parametro + 1);
}


int main() {

    int param[] = {2, 3};

    printf( "%i\n",
            suma(param)
    );

    return EXIT_SUCCESS;
}
