#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>


int main(int argc, char *argv[]) {

    struct hostent *informacion;

    if (argc < 2){
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return EXIT_FAILURE;
    }

    informacion = gethostbyname(argv[1]);

    printf("Nombre oficial del nodo: %s\n", informacion->h_name);
    printf("Alias: %s\n", informacion->h_aliases[0]);
    printf("Tipo de dirección: %i\n", informacion->h_addrtype);
    printf("Longitud de la dirección: %i\n", informacion->h_length);
    printf("Direccion 0 del servidor: %lX\n", * (unsigned long *) informacion->h_addr_list[0]);


    return EXIT_SUCCESS;
}
