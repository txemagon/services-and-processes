#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

sig_atomic_t hijos = 0;

const char *comando[3][4] = {
    {"mail", "-dsharklasers.com", "email.addr", NULL},
    {"mail", "-dsharklasers.com", "email.addr", NULL},
    {"mail", "-dsharklasers.com", "email.addr", NULL}
};

void
spawn(const (const char *lp[])
{
    pid_t tengo_hijo = fork();

    if (tengo_hijo){
        hijos++;
        return;
    }

    execvp(lp[0], lp);
    fprintf(stderr, "We couldn't run %s.\n", lp[0]);
}


int
main(int argc, char *argv[])
{
    spawn(comando[0]);

    return EXIT_SUCCESS;
}
