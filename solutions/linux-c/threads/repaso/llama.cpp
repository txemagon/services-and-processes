#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct Binario {
    int op1;
    int op2;
};

struct Monario {
    int op;
};

int no(void *op){
    struct Monario *operando = (struct Monario *) op;
    return ~operando->op;
}

int y(void *op) {
    struct Binario *operando = (struct Binario *) op;
    return operando->op1 & operando->op2;
}

int o(void *op) {
    struct Binario *operando = (struct Binario *) op;

    return operando->op1 | operando->op2;
}


int llama(int (*f)(void *), void *datos){

    return f(datos);
}

int main(int argc, char *argv[]) {

    struct Monario a = {27};
    struct Binario b = {24, 15};
    struct Binario c;
    c.op1 = 9;
    c.op2 = 14;


    printf("%i\n", llama(&no, (void *) &a));
    printf("%i\n", llama(&o,  (void *) &b));
    printf("%i\n", llama(&y,  (void *) &c));

    return EXIT_SUCCESS;
}
