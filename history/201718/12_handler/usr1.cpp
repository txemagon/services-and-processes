#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <strings.h>
#include <unistd.h>

sig_atomic_t veces = 0;
const char *msj[] = {
  "No moriré.",
  "No me rendiré.",
  "Hasta la victoria."
};

void
manejador (int n_sig)
{
  printf ("%s\n", msj[veces++]);
}

int
main (int argc, char *argv[])
{
  struct sigaction sa;
  bzero (&sa, sizeof (sa));
  sa.sa_handler = &manejador;
  sigaction (SIGUSR1, &sa, NULL);

  while (veces < 3) usleep (10000);

  printf ("Adios, mundo cruel.\n");

  return EXIT_SUCCESS;
}
