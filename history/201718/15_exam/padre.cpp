#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

#include "common.h"

/*  make all && sudo make install */

const char *progname = "./hijo";

struct TBuffer
{
  char *data;
  int size;
} buffer;
sig_atomic_t fin = 0;

void
push (char c)
{
  buffer.data = (char *) realloc (buffer.data, ++buffer.size);
  buffer.data[buffer.size - 1] = c;
}

void
got (int signum)
{
  static int pot = 1;
  static char c = 0;

  DBG("[%i]", signum == SIGUSR2);
  c += pot * (signum == SIGUSR2);
  pot <<= 1;

  if (pot >= 0x100)
    {
      pot = 1;
      if (c == (char) EOF)
	{
	  push ('\0');
          DBG("\nEnd of reception.\n");
	  fin = 1;
	}
      else
	push (c);
      DBG("\nRecived: 0x%Xh\n", c);
      c = 0;
    }
}

pid_t
spawn ()
{
  pid_t son = 0;

  if ((son = fork ()))
    return son;

  execlp (progname, progname, (char *) NULL);
  fprintf (stderr, "Something went wrong with: %s\n", progname);
  exit (EXIT_FAILURE);

  return (pid_t) 0;
}


int
main (int argc, char *argv[])
{
  pid_t son = 0;
  int exit_status;
  struct sigaction s1, s2;

  bzero (&buffer, sizeof (buffer));
  bzero (&s1, sizeof (s1));
  bzero (&s2, sizeof (s2));
  son = spawn ();
  s1.sa_handler = &got;
  s2.sa_handler = &got;
  sigaction(SIGUSR1, &s1, NULL);
  sigaction(SIGUSR2, &s2, NULL);

  while (!fin)
    usleep (100000);

  wait (&exit_status);

  if (WIFEXITED (exit_status))
    printf ("\nMESSAGE:\n%s\n", buffer.data);
  else
    fprintf (stderr, "Abnormal termination of: %s.\n", progname);

  free (buffer.data);

  return EXIT_SUCCESS;
}
