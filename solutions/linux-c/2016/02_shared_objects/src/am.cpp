#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "ticket.h"

int main(int argc, char *argv[]) {

    printf("Entrada %i adjudicada para el socio del Atlético de Madrid.\n", ticket());

    return EXIT_SUCCESS;
}
