#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include <readline/readline.h>
#include <readline/history.h>

#include "common.h"

#define MAX 0xFFFF

void halt(const char * mssg){
    perror(mssg);
    exit(-1);
}

void cli(int fd){

    int quit = 0;
    char buffer[MAX];

    pop(fd, buffer);
    printf("%s", buffer);
    do {
        char *line = readline("Chat> ");
        if (line && *line)
            add_history (line);
        push(fd, line);

        if (!strcasecmp(line, "quit"))
            quit = 1;

        free(line);
    } while(!quit);
}

int main(int argc, char *argv[]) {
    int socket_fd;
    struct sockaddr_in server;
    struct hostent *he;

    if (argc < 3){
        fprintf(stderr, "%s <host> <puerto>\n", argv[0]);
        exit(-1);
    }


    if( (socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        halt("Socket");


    server.sin_family = AF_INET;
    if ((he = gethostbyname(argv[1])) == NULL)
        halt("DNS");
    server.sin_addr = *( (struct in_addr *) he->h_addr);
    bzero(&server.sin_zero, sizeof(server.sin_zero));
    server.sin_port = htons(atoi(argv[2]));

    if ( connect(socket_fd, (struct sockaddr *) &server, sizeof(struct sockaddr)) == -1)
        halt("connect");

    cli(socket_fd);

    close(socket_fd);

    return EXIT_SUCCESS;
}
