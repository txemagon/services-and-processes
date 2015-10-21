#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    char nombre[0x20];
    
    printf("dime tu nombre: ");
    scanf(" %s", nombre);

    printf("Hola %s\n", nombre);
    fprintf(stderr, "Ha habido un error.\n");

   return EXIT_SUCCESS;
}
