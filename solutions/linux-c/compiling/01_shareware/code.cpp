#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[]) {

   printf("Esto es un juego que mola\n");
#ifndef SHAREWARE
   printf("que te cagas. Gracias por pagar.\n");
#endif

   return EXIT_SUCCESS;
}
