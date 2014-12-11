#include <stdlib.h>
#include <stdio.h>

#include "common.h"

void ohoh(const char *mssg){
	perror(mssg);
	exit(EXIT_FAILURE);
}

