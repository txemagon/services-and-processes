#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int *p = (int *) malloc(sizeof(int));
    *p = 4;
    printf("%p -> %p: %i\n", &p, p, *p);
    free(p);

    int *m = (int *) malloc(2 * sizeof(int));
    *m = 5;
    *(m+1) = 6;
    printf("%p \n %p: %i\n %p: %i\n", &m, m, *m, m+1, *(m+1));
    free(m);
    return EXIT_SUCCESS;
}
