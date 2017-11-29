#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>

#include "common.h"
#include "comm.h"


int
main(int argc, char *argv[])
{
    pid_t ppid = getppid();
    char c;

    DBG("Start reading.\n")
    DBG("Type Ctrl-D to finish.\n")
    while ( (c = getchar()) != EOF )
        enviar(ppid, (unsigned char) c);
    enviar(ppid, (unsigned char) c);
    DBG("End reading.\n")

    return EXIT_SUCCESS;
}
