#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int f();    // funcion que devuelve un entero.
int *f();   // funcion que devuelve un puntero a un entero.
int (*f)(); // puntero a una funcion que devuelve un entero.

int f()[];  // funcion que devuelve un array de enteros.
int f[]();  // Array de funciones.

int *(*f)()[]; // Puntero a una funcion que devuelve una array de punteros a entero.
int *(*f()); // == funcion que devuelve un punero a -> (puntero a entero)
int **f();



int main(int argc, char *argv[]) {
    int A[N];    // Array de enteros
    int *A[N];   // Array de punteros a entero.
    int (*A)[N]; // Puntero a un array de enteros.



   return EXIT_SUCCESS;
}
