#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct Operando {
    int op1;
    int op2;
};

int suma(int op1, int op2) { return op1 + op2; }

int add(struct Operando op){
    return op.op1 + op.op2;
}

int main(int argc, char *argv[]) {

    struct Operando a;
    a.op1 = 2;
    a.op2 = 3;

    add(a);

    suma(2,3);

   return EXIT_SUCCESS;
}
