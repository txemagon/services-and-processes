#include <stdio.h>
#include <stdlib.h>

#include "interfaz.h"

void print_usage(const char *command) {
    fprintf(stderr, "Usage: %s <error>\n", command);
    exit(1);
}
