#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#include "common.h"

#define CONCURRENCY 5
#define MAX 0xFFFF
#define N 0x20

struct TArg{
    int fd;
    char origin[N];
};

const char welcome[] =
  "C · H · A · T\n"
  "Bienvenido al chat.\n\n"
  "'quit' para abandonar el chat.\n\n";

int clients = 0;

void halt(const char *where){
    perror(where);
    exit(-1);
}

void *pop_out(void *args){
    struct TArg *arg = (struct TArg *) args;
    int fd = arg->fd;
    int r = 0;
    int quit = false;
    char buffer[MAX];
    push(fd, welcome);
    pthread_detach(pthread_self());

    do {
        do {
            r = pop(fd, buffer);
            if (r){
                if (!strcmp(buffer, "quit"))
                    quit = true;
                // La escritura debería estar sincronizada en un mutex.
                printf("[%s]: %s\n", arg->origin, buffer); 
            }
        } while(r);
    } while(!quit);

    close(fd);
    clients--;
    printf("%i\n", clients);
    return NULL;
}

int main(int argc, const char *argv[]){
    bool up = false;
    int socket_fd;
    struct sockaddr_in server;

    if (argc < 2){
        fprintf(stderr, "%s <puerto>\n", argv[0]);
        exit(-1);
    }

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(atoi(argv[1]));
    bzero(&server.sin_zero, sizeof(server.sin_zero));

    if ( bind(socket_fd, (struct sockaddr *) &server, sizeof(struct sockaddr) ) == -1 )
        halt("Bind");

    if (listen(socket_fd, CONCURRENCY) == -1)
        halt("listen");

    printf("C · H · A · T\n");
    printf("Chat Server up on port %s\n\n", argv[1]);

    while(1) {
        pthread_t thread_id;
        struct sockaddr_in client;
        socklen_t client_len = (socklen_t) sizeof(struct sockaddr);
        int client_fd;
        struct TArg args;

        if ( (client_fd =
                    accept(
                        socket_fd,
                        (struct sockaddr *) &client,
                        &client_len
                        )) == -1 )
            halt("accept");

        args.fd = client_fd;
        strncpy(args.origin, inet_ntoa(client.sin_addr), N);
        args.origin[N-1] = '\0';
        pthread_create(&thread_id, NULL, &pop_out, &args);
        clients++;

    }

    close(socket_fd);

    return EXIT_SUCCESS;
}
