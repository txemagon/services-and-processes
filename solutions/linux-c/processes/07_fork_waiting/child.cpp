#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char **argv) {

    FILE *pf = NULL;

    if (argc < 2){
        fprintf(stderr, "Oh, my God! I need a file to open.\n");
        exit(EXIT_FAILURE);
    }

    if ( !(pf = fopen(argv[1], "w")) ) {
        fprintf(stderr, "Oh, my God! I couldn't find open your file.\n");
        exit(EXIT_FAILURE);
    }

    sleep(5);
    fprintf(pf,"The world is a vampire.\n");

    fclose(pf);
    return EXIT_SUCCESS;
}
