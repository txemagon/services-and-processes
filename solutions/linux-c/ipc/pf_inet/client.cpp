#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <strings.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "common.h"

void ask(int fd){

    char *buffer;
    int keep_on;

    do {
	buffer = readline("Chat> ");
	if (buffer && *buffer)
	    add_history(buffer);
	int len = strlen(buffer) + 1;
	write(fd, &len, sizeof(len));
	write(fd, buffer, len);
	keep_on = strcasecmp(buffer, "quit") && strcasecmp(buffer, "exit");
	free(buffer);
    } while (keep_on);
}

int main(int arg, char *argv[]){

    int socket_fd;
    struct sockaddr_in address;
    struct hostent *he;

    if ( (socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	ohoh("Socket.");

    address.sin_family = AF_INET;
    he = gethostbyname(argv[1]);
    address.sin_addr = *( (struct in_addr *) he->h_addr);

    address.sin_port = htons(atoi(argv[2]));
    bzero(&address.sin_zero, sizeof(address.sin_zero));

    connect(socket_fd, (struct sockaddr *) &address, sizeof(struct sockaddr));
    ask(socket_fd);

    close(socket_fd);

    return EXIT_SUCCESS;
}
