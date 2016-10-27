#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include "queue.h"

#define NOMBRES (sizeof(catalog) / sizeof (const char *))
#define JAOMENY (sizeof(name)    / sizeof (const char *))
#define PMAX100 20000

Queue bargain[2];

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
    "Wig",
    "Szuwarowski"
};

void fill(Queue *list, int n, const char *name) {
    Product new_product;

    strncpy(list->name, name, NMAX);

    for (int i=0; i<n; i++){
        strncpy(new_product.name, catalog[rand() % NOMBRES], NMAX);
        new_product.price = (rand() % PMAX100) / 100.;
        new_product.off = (rand() % 100) / 100.;
        push(list, new_product);
    }
}

void print(Queue q){
    for (int i=q.init; i<q.summit; i++)
        printf("%s: %s - %.2lf (%.2lf)\n", q.name,
                q.data[i].name, q.data[i].price, q.data[i].off);
}

void *lady(void *data){
    const char *name = (const char *) data;

    Product grab;
    int b_n;



    for (int i=0; i< 1000; i++) {
        b_n = rand() % 2;
        grab  = shift(&bargain[b_n]);
        printf("[%s] %s: I take a %s for %.2lf\n",
                bargain[b_n].name,
                name, grab.name, grab.price * (1 - grab.off));
        usleep(1000);
    }

    return NULL;
}

int main() {
    pthread_t thr_id[5];
    const char *name[] = {
        "Josefa",
        "Maria",
        "Huan Lu",
        "Gandy",
        "Oski Ero"
    };

    srand(time(NULL));
    init(&bargain[0]);
    init(&bargain[1]);
    fill (&bargain[0], 8000, "The English Cut");
    fill (&bargain[1], 8000, "Appreciated Halls");

    for (unsigned i=0; i < JAOMENY; i++)
        pthread_create(&thr_id[i], NULL, &lady, (void *) name[i]);

    for (unsigned i=0; i<JAOMENY; i++)
        pthread_join(thr_id[i], NULL);

    return EXIT_SUCCESS;
}
