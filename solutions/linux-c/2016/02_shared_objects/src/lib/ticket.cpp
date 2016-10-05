#include "ticket.h"


int ticket(){
    static int ticket = 0;

    return ++ticket;
}
