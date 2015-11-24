#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>

// Explicación Alemana (Comment Ario)
// 0x1000 == 4kb

int main() {

    // Conseguir una página de memoria compartida.
    // shmget(NUMERO_UNICO, TAMAÑO, PERMISOS COMO SI FUERA UN FICHERO);
    int clave = shmget(IPC_PRIVATE, 0x1000,
            IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR );

    /* BLOQUE 1 */
    // Escribir en la memoria compartida.
    // Creo una variable en la memoria compartida

    char *mi_nombre = (char *) shmat(clave, (void *) 0, 0);
    // La uso
    sprintf(mi_nombre, "Me llamo Juan.\n");
    // La destruyo (la variable).
    shmdt(mi_nombre);

    /* BLOQUE 2 */
    // Leer de la memoria compartida.

    // Crear otra variable (distinta) en la memoria compartida.
    char *su_nombre = (char *) shmat(clave, (void *) 0x3000000, SHM_RDONLY);
    // La uso
    printf("El me dijo: %s", su_nombre);
    // La destruyo (la variable)
    shmdt(su_nombre);



    // Destruyo la página de memoria compartida.
    shmctl(clave, IPC_RMID, 0);

    return EXIT_SUCCESS;
}
