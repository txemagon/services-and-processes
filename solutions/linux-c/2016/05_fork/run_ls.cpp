#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void
spawn(const char *command, char *args[])
{
    pid_t hijid = fork();
    if (!hijid)
    {
        execvp(command, args);
        fprintf(stderr, "Oops. Something went wrong.\n");
    }
}

int
main (int argc, char *argv[])
{

    int salida;
    spawn("ls", argv);

    printf("Waiting for my son.\n");
    wait(&salida);
    printf("Game over.\n");

    return 0;
}
