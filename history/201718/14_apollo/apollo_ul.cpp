#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>

#define M 0x100
#define N 0x10

sig_atomic_t hijos = 0;

/*
// Nota marginal
const int i = 3;              // La forma antigua
int const i = 3;              // La forma coherente.

char const *p = NULL;         // puntero a una constante
char * const p = NULL;        // puntero fijo
char const * const p = NULL;  // Puntero fijo a una constante
const char * const p = NULL;  // La forma vieja de ^^^^^^^
*/

char const * const comando[] = {
    "./mail -dsharklasers.com email.addr",
    "./mail -dsharklasers.com email.addr",
    "./mail -dsharklasers.com email.addr",
    "./mail -dsharklasers.com email.addr",
    NULL
};

void
spawn(char const * lp)
{
    int i = 0;
    char *argv[N];
    char str[M];
    char *p_str = str;
    // Sólo del padre
    pid_t tengo_hijo = fork();
    if (tengo_hijo){
        hijos++;
        return;
    }

    // Sólo del hijamente
    bzero(argv, sizeof(argv));
    strncpy(str, lp, M);
    while ( (argv[i++] = strtok(p_str, " ")) )
        p_str = NULL;

    execvp(argv[0], argv);
    fprintf(stderr, "We couldn't run %s.\n", argv[0]);
}

void
undertaker(int ruisignal)
{
    int estado_de_salida;
    hijos--;
    wait(&estado_de_salida);

    /* Abstenerse de printfs en los manejadores  */
/*
    if (WIFEXITED(estado_de_salida))
        fprintf(stderr, "Muerte natural: %i\n", WEXITSTATUS(estado_de_salida));
    else
        fprintf(stderr, "Muerte desnatada.\n");
    fprintf(stderr, "%i hijos restantes.\n", hijos);
    */
}

int
main(int argc, char *argv[])
{
    struct sigaction como_gestionar;

    bzero(&como_gestionar, sizeof(como_gestionar));
    como_gestionar.sa_handler = &undertaker;
    sigaction(SIGCHLD, &como_gestionar, NULL);

    for (int i=0; comando[i]!=NULL; i++)
        spawn(comando[i]);

    /* Cosas Belgas */
    sleep(3);

    /* Die ende */
    while (hijos) {
        fprintf(stderr, "Esperando para terminar. %i hijos restantes.\n",
                hijos);
        usleep(100000);
    }

    printf("The World is a vampire.\n");

    return EXIT_SUCCESS;
}
