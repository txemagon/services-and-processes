#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>

#define M 0x100
#define N 0x10

sig_atomic_t hijos = 0;

char const * const comando[] = {
    "./mail -vdsharklasers.com email.addr",
    NULL
};

void
spawn(char const * lp)
{
    int i = 0;
    char *argv[N];
    char str[M];
    char *p_str = str;

    pid_t tengo_hijo = fork();

    if (tengo_hijo){
        hijos++;
        return;
    }

    bzero(argv, sizeof(argv));
    strncpy(str, lp, M);
    while ( (argv[i++] = strtok(p_str, " ")) )
        p_str = NULL;

    execvp(argv[0], argv);
    fprintf(stderr, "We couldn't run %s.\n", argv[0]);
}


int
main(int argc, char *argv[])
{
    spawn(comando[0]);

    return EXIT_SUCCESS;
}
