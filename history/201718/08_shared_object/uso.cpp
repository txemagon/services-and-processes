#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mates.h"

int
main(int argc, char *argv[])
{

    printf("2 + 3 = %i\n", suma(2,3));
    printf("25 AND 19 = %i\n", AND(25,19));

    return EXIT_SUCCESS;
}
