#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

#define N 0x100
#define M 0x10
#define PROMPT "MA-TEOS$> "

void
spawn (char buffer[N])
{
    char *argv[M];
    int i = 0;
    pid_t mijo = 0;

    while( argv[i++] = strtok(buffer, " ") )
        buffer = NULL;

    strtok(argv[i-2], "\n"); // Remove newline

    mijo = fork();
    if (mijo)
        return;

    // execv("/usr/bin/firefox", ["firefox", "index.html", NULL]);
     execvp(argv[0], argv);
     fprintf (stderr, "No he podido ejecutar: %s\n", argv[0]);
     exit(1);
}

int
main (int argc, char *argv[])
{
  //char buffer[N];
  char *buffer[N];

  while (1)
    {
      //printf (PROMPT);
      //fgets (buffer, N, stdin);
      readline ( PROMPT );
      spawn (buffer);
     
    }

  return EXIT_SUCCESS;
}
