#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


void *print(void *parameter) {
    char *caracter = (char *) parameter;

    for (int i=0; i<1000000; i++)
        fputc(*caracter, stderr);

    return NULL;
}

int main(){

    pthread_t thread_id1, thread_id2;
    char x = 'x';
    char o = 'o';

    pthread_create(&thread_id1, NULL, &print, &x);
    pthread_create(&thread_id2, NULL, &print, &o);

    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);

    printf("\n");

   return EXIT_SUCCESS;
}

