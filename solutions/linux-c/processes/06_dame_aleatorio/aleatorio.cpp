#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {

    FILE *pf;

    srand(time(NULL));

    pf = fopen("numero", "w");
    fprintf(pf, "%i\n", rand());
    fclose(pf);

   return EXIT_SUCCESS;
}
