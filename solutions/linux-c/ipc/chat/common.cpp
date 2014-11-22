#include <string.h>
#include <unistd.h>
#include "common.h"

int pop(int fd, char *buffer){
    int length;
    read(fd, &length, sizeof(length));
    return read(fd, buffer, length);
}


int push(int fd, const char *mssg){
    int length = strlen(mssg) + 1;
    write(fd, &length, sizeof(length));
    write(fd, mssg, length);
}

