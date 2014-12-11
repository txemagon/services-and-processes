#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <pthread.h>

#include "common.h"

#define BACKLOG 5

const char *saludo = "Hi> ";

int quit = 0;

struct TArg{
    int fd;
};

void *chat_with_client(void *argument){
    int fd = ((struct TArg *) argument)->fd;
    int buflen = 0;
    char buffer[80];

    pthread_detach(pthread_self());
    do {
	if  (read(fd, &buflen, sizeof(int)) == -1 )
	    ohoh("Read Length.");

	if ( read(fd, buffer, buflen) == -1)
	    ohoh("Read mssg.");
	if (strcasecmp(buffer, "quit") == 0){
	    quit = 1;
	    close(fd);
	    return NULL;
	}
	
	if (strcasecmp(buffer, "exit") == 0){
	    close(fd);
	    return NULL;
	}

	printf("%s\n", buffer);
    } while(1);

    return 0;
}


int main(int argc, char *argv[]){

    int incomming_socket;
    struct sockaddr_in address;


    /* Crear el socket */
    if (argc<2){
	fprintf(stderr, "%s <numero de puerto>\n", argv[0]);
	return EXIT_FAILURE;
    }

    if ( (incomming_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	ohoh("Socket");


    /* BIND */
    address.sin_family = AF_INET;
    address.sin_port = htons( atoi(argv[1]) );
    address.sin_addr.s_addr = INADDR_ANY;
    bzero(address.sin_zero, sizeof(address.sin_zero));

    if (bind(incomming_socket, (struct sockaddr*) &address, sizeof(address)) == -1)
	ohoh("Bind");

    if ( listen(incomming_socket, BACKLOG) == -1)
	ohoh("Listen");

    do {
	int client_fd;
	struct TArg arg;

	struct sockaddr_in client_config;
	socklen_t len = sizeof(client_config);
	pthread_t hilo;

	if ( (client_fd = accept(incomming_socket, (struct sockaddr *) &client_config, 
			&len)) == -1)
	    ohoh("Accept.");

	arg.fd = client_fd;
	pthread_create(&hilo, NULL, chat_with_client, (void *) &arg);

    } while(!quit);

    close(incomming_socket);
    return EXIT_SUCCESS;
}
