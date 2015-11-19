#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char buffer[0x100];

    printf("Nombre: ");
    scanf("%s", buffer);

    if (!strcasecmp("claudia", buffer)) { // Metieron la cadena vacía.
        fprintf(stderr, "Estamos empachados de ciruelas como tú.\n");
        printf("Nombre: ");
        scanf("%s", buffer);
    } else
        printf("Hola, %s, guapetona.\n", buffer);

    while(1);

    return EXIT_SUCCESS;
}
