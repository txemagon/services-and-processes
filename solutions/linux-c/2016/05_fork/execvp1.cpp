#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    pid_t hijo_pid;
    char *mi_programa[] = {
        "firefox",
        NULL
    };

    hijo_pid = fork();
    if (hijo_pid == 0){
        execvp("firefox", mi_programa);
        printf("Esto no se ejecuta normalmente.\n");
    }

   return EXIT_SUCCESS;
}
