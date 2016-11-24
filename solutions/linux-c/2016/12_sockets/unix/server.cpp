#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

void talk_to(int pipe){
    ;
}

int main(int argc, char *argv[]) {

    const char *const sock_name = argv[1];
    struct sockaddr_un s_filedata;
    s_filedata.sun_family = AF_LOCAL;
    strcpy(s_filedata.sun_path, argv[1]);

    int socket_fd = socket(PF_UNIX, SOCK_STREAM, 0);
    bind(socket_fd, (struct sockaddr *) &s_filedata, SUN_LEN(&s_filedata));
    listen(socket_fd, 5);

    do {
        struct sockaddr_un who_are_you;
        socklen_t who_len;

        int new_connection_fd = accept(socket_fd,
                (struct sockaddr *) &who_are_you, &who_len);

        talk_to(new_connection_fd);
        close(new_connection_fd);

    } while(1);

    close(socket_fd);
    unlink(sock_name);

    return EXIT_SUCCESS;
}
