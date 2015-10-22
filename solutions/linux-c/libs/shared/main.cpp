#include <stdio.h>
#include <stdlib.h>

#include "mat.h"
#include "pretty.h"

int main(int argc, char **argv) {
    pprint("SuperPrograma");

    printf( "\n 2 + 3 = %i\n", 
	    (int) suma(2, 3) );

    return EXIT_SUCCESS;
}

