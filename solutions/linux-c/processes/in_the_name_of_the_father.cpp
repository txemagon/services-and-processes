#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

sig_atomic_t seguir = 1;

void requiem(int signal_number){
   seguir = 0;
}

void spawn(char *argv[]){

   pid_t my_sunshine = fork();

   if (my_sunshine)
      return;
   else {
      execvp(argv[1], argv + 1);
      fprintf(stderr, "Oh! Oh!\n");
      seguir = 0;
   }
}

int main(int argc, char *argv[]) {
   struct sigaction sa;
   memset(&sa, 0, sizeof(sa));
   sa.sa_handler = &requiem;
   
   sigaction(SIGCHLD, &sa, NULL);
   spawn(argv);

   while(seguir) 
      printf("laaaa lala laa la la lala la\n");

   printf("DEP\n");

   return EXIT_SUCCESS;
}
