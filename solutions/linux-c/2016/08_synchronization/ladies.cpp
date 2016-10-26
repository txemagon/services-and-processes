#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include "queue.h"

#define NOMBRES (sizeof(catalog) / sizeof (const char *))
#define PMAX100 20000

Queue bargain;

const char *catalog[] = {
    "Umbrella",
    "Handbag",
    "Hat",
    "Trousers",
    "Pants",
    "Swimming Trunks",
    "Earrings",
    "Rings",
    "Skirt",
    "Thong",
    "Wig"
};

void fill(Queue *list, int n) {
    Product new_product;

    for (int i=0; i<n; i++){
        strncpy(new_product.name, catalog[rand() % NOMBRES], NMAX);
        new_product.price = (rand() % PMAX100) / 100.;
        new_product.off = (rand() % 100) / 100.;
        push(list, new_product);
    }
}

void print(Queue q){
    for (int i=q.init; i<q.summit; i++)
        printf("%s - %.2lf (%.2lf)\n",
                q.data[i].name, q.data[i].price, q.data[i].off);
}

void *lady(void *data){
    const char *name = (const char *) data;

    Product grab;

    while(bargain.summit - bargain.init > 0){
        grab  = shift(&bargain);
        printf("%s: I take a %s for %.2lf\n",
                name, grab.name, grab.price * (1 - grab.off));
        usleep(1000);
    }

    return NULL;
}

int main() {
    pthread_t thr_id[2];
    const char *name[] = {
        "Josefa",
        "Maria"
    };

    srand(time(NULL));
    init(&bargain);
    fill (&bargain, 8000);

    pthread_create(&thr_id[0], NULL, &lady, (void *) name[0]);
    pthread_create(&thr_id[1], NULL, &lady, (void *) name[1]);

    for (int i=0; i<2; i++)
        pthread_join(thr_id[i], NULL);

    return EXIT_SUCCESS;
}
