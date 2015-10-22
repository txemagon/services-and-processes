#include <stdio.h>
#include <stdlib.h>

void pprint(const char *mssg) {
    char final_mssg[0x100];

    sprintf(final_mssg, "toilet -Fborder --gay -f term '%s'", mssg);

    system(final_mssg);
}

