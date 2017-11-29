#include "comm.h"
#include "common.h"
#include <unistd.h>

int bit[] = { SIGUSR1, SIGUSR2 };

void
enviar (pid_t parent, unsigned char data)
{
  DBG ("Sending: 0x%Xh = ", data);
  for (int c = 0; c < 8; data >>= 1, c++)
    {
      kill (parent, bit[data % 2]);
      DBG ("%i", data % 2);
      usleep(10000);
    }
  DBG("\n");
}
