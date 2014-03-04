#include <stdio.h>
#include <stdlib.h>

int suma_hasta(int limite){
   int resultado = 0;

   if (limite < 0)
      return 0;
   resultado = limite + suma_hasta(limite - 1);
   printf("%i\n", resultado);

   return resultado;
}

int main(int argc, char *argv[]) {

   int limite = atoi(argv[1]);

   suma_hasta(limite);

   return EXIT_SUCCESS;
}
