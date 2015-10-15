#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

#include "titulo.h"
#include "funciones.h"


double dame(const char *titulo) {
   double dato;

   printf("Introduce %s: ", titulo);
   scanf(" %lf", &dato);
   
   return dato;
}

void display_usage() {
	printf("chungo!\n");
}

int main(int argc, char *argv[]) {
 
   double op1, op2, resultado;
   int next_option;

   const char * const short_options = "h";
   static struct option long_options[] = {
       {"help", no_argument, NULL, 'h'},
       {0, 0, 0, 0}
   };

   do {
     next_option = getopt_long(argc, argv, short_options, long_options, NULL);
     switch (next_option){
        case 'h':
                  display_usage();
                  break;

        case -1:
		  break;
        case '?':
		  display_usage();
     }
   } while ( next_option != -1 );

   titulo();

   op1 = dame("Operando 1");
   op2 = dame("Operando 2");
   resultado = sum(op1, op2);

   printf( " %.2lf + %.2lf = %.2lf\n", 
           op1, op2, resultado ); 

   return EXIT_SUCCESS;
}
