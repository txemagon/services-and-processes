#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#define MAX 0xFFFFFFFF

struct TPrime {
    unsigned *primes;
    unsigned summit;
} primes;

void push(struct TPrime *stack, unsigned data){
    stack->primes[stack->summit++] = data;
}

bool is_prime(unsigned candidate){

    for (unsigned i=0; i<primes.summit; i++)
        if (candidate % primes.primes[i] == 0)
            return false;

    return true;
}

#define prime_push(var, index,  x)                     \
  (var) = 6 * (index) +(x);                          \
        if (is_prime((var))){                  \
            push(&primes, (var));              \
            fprintf(stderr, "%lu - %llu\n", (index), (var));  \
        }                                      \


void *find_primes(void *){
    unsigned long long i;
    for (unsigned long k = 1; k<MAX; k++){
        prime_push(i, k, -1);
        prime_push(i, k, +1);
        }

    return NULL;
}

void *get_time(void *){

    time_t elapsed;
    struct tm *local;
    char printable_time[0x100];

    while(1){
        elapsed = time(NULL);
        local = localtime(&elapsed);
        strftime(printable_time, 0x100, "%A, %d/%m/%Y %H:%M:%S", local);

        printf("\r%s                        ", printable_time);
        fflush(stdout);
        sleep(1);
    }

    return NULL;
}

int main() {

    pthread_t fn_primes_id, fn_time_id;

    primes.primes = (unsigned *) malloc( 64000000 * sizeof(unsigned));
    push(&primes, 2);
    push(&primes, 3);

    pthread_create(&fn_primes_id, NULL, find_primes, NULL);
    pthread_create(&fn_time_id, NULL, get_time, NULL);

    pthread_join(fn_primes_id, NULL);
    pthread_join(fn_time_id, NULL);

    free(primes.primes);

    return EXIT_SUCCESS;
}
