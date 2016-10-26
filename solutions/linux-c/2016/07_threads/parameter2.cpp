#include <stdio.h>
#include <stdlib.h>

struct Param {
    int op1;
    int op2;
};

int suma(void *parametros){
    struct Param *p = (struct Param*) parametros;

    int resultado = 0;

    resultado = p->op1 + p->op2;

    return resultado;
}

int main() {

    struct Param param = {2, 3};

    printf("%i\n", suma(&param));

    return EXIT_SUCCESS;
}
