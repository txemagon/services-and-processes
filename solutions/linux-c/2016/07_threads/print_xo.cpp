#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void *printf_xs(void *unused) {

    while(1)
        fputc('x', stderr);

    return NULL;
}

int main(){

    pthread_t thread_id;

    pthread_create(&thread_id, NULL, &printf_xs, NULL);

    while(1)
        fputc('o', stderr);

   return EXIT_SUCCESS;
}

