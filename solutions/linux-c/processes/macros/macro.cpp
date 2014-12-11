#include <stdio.h>
#include <stdlib.h>

#define EURO 166.386
#define EUROS(x) ((x) / EURO)

int main() {
    int pesetas = 8000;
    printf("%i pts. son %.2lf euros\n", 
	    pesetas, 
	    EUROS(pesetas));
    return EXIT_SUCCESS;
}
