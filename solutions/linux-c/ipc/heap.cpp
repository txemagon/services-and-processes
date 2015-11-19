#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int *p = (int *) malloc(sizeof(int));
    *p = 6;
    printf("%p -> %p: %i\n", &p, p, *p);
    free(p);

    int *m = (int *) malloc(2 * sizeof(int));
    *m = 5;       // m[0]
    *(m+1) = 6;   // m[1]
    printf("%p \n %p: %i\n %p: %i\n", &m, m, *m, m+1, *(m+1));
    free(m);
    return EXIT_SUCCESS;
}

/* 
    RESERVA DE UN ENTERO

             [3579]
              +-+
              |6|
              +-+
               ^
HEAP           |
---------------+----------------
VARIABLES      |
               |
             +-+-+
             | | |
             | o |
             |   |
             +---+
             p [1256]

*/

/*

RESERVA DE UN ARRAY ENTEROS

             [3579]
              +-+-+
              |5|6|
              +-+-+
               ^
HEAP           |
---------------+----------------
VARIABLES      |
               |
             +-+-+
             | | |
             | o |
             |   |
             +---+
             m [1256]

*/

/*

1000+----------------+
    |     stack      |
    +-------+--------+
    |       |        |
    |       V        |
    |                |
    |     heap       |
    |                |
    +----------------+
    |   variables    |
    +----------------+
    |                |
    |                |
    |    código      |
    |                |
    |                |
0   +----------------+


*/
