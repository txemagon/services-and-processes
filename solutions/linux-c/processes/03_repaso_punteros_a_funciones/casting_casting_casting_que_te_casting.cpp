#include <stdio.h>
#include <stdlib.h>

struct TParametro {
   int param1;
   double param2;
};

double lineal(void *p) {
   double *x = (double *) p;
   return *x;
}

double parabola(void *p) { 
   double *x = (double *) p;
   return *x * *x; 
}

double cubo(void *p) { 
   double *x = (double *) p;
   return *x * *x * *x; 
}

double integral( double (*f)(void *) ){
   double area = 0;
   double base = 0.001;

   for (double i=0; i<7; i+=base)
      area += f(&i);
   area *= base;
   
   return area;
}

int main(int argc, char *argv[]) {

   int opcion;
   double (*p)(void *);
   double (*funcion[])(void *) = { &lineal, &parabola, &cubo };

   p = &parabola;

   struct TParametro p;
   p.param1 = 7;
   p.param2 = 2.5


   printf("\t1.- lineal.\n"
	  "\t2.- parabola.\n"
	  "\t3.- cubo.\n"
	  "\nOpcion: ");
   scanf(" %i", &opcion);

   printf("Integral(7) = %.2lf\n",integral(funcion[opcion-1]) );

   return EXIT_SUCCESS;
}
