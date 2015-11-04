#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define ANCHO 0.00005

double parabola(double x){
    return x*x;
}

double logaritmo(double x){
    return log(x);
}

double integra( double (*f)(double),
                double xmin,
                double xmax) {
    double suma = 0;

    for (double x=xmin; x<xmax; x+=ANCHO)
        suma += f(x);

    return suma * ANCHO;
}

int main(int argc, char *argv[]) {

    printf("%.2lf\n", integra(&parabola, 1, 5));
    printf("%.2lf\n", integra(&logaritmo, 1, 5));

    return EXIT_SUCCESS;
}
