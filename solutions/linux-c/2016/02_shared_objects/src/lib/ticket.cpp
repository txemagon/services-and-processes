#include "ticket.h"


int ticket(){
    // Ojo con los static en los
    // so: que los descarga de memoria.
    // Esto no funcionaría
    static int ticket = 0;

    return ++ticket;
}
