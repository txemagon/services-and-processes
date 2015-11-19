#include <stdio.h>
#include <stdlib.h>


int main() {

    // Conseguir una página de memoria compartida.
    // shmget(NUMERO_UNICO, TAMAÑO, PERMISOS COMO SI FUERA UN FICHERO);
    shmget(IPC_PRIVATE, 0x1000, S_IRUSR | S_IWUSR);

    /* BLOQUE 1 */
    // Escribir en la memoria compartida.
    // Creo una variable en la memoria compartida

    char *mi_nombre = shmat();
    // La uso
    sprinf(mi_nombre, "Me llamo Juan.\n");
    // La destruyo (la variable).
    shmdt();


    /* BLOQUE 2 */
    // Leer de la memoria compartida.

    // Crear otra variable (distinta) en la memoria compartida.
    char *su_nombre = shmat();
    // La uso
    printf("El me dijo: %s", su_nombre);
    // La destruyo (la variable)
    shmdt();



    // Destruyo la página de memoria compartida.
    shmctl();

    return EXIT_SUCCESS;
}
