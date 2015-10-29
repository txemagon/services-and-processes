#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

   printf("My Process ID is: %i\n", getpid());
   printf("My Parent Process ID is: %i\n", getppid());

   return EXIT_SUCCESS;
}
