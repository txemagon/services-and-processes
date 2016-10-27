#ifndef __queue_h__
#define __queue_h__

#include <pthread.h>


#define NMAX 0x100
#define QMAX 0x10000

typedef struct TProduct {
    char name[NMAX];
    int id;
    double price;
    double off;
} Product;

typedef struct TQueue {

    char name[NMAX];
    Product data[QMAX];
    int init;
    int summit;
    pthread_mutex_t mutex;

} Queue;

#ifdef __cplusplus
extern "C" {
#endif

    extern void init(Queue *q);
    extern void push(Queue *q, Product p);
    extern Product shift(Queue *p);

#ifdef __cplusplus
}
#endif

#endif
