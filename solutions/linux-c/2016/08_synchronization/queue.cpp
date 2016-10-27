#include "queue.h"
#include <string.h>

void init(Queue *q) {
    q->init = q->summit = 0;
    q->mutex = PTHREAD_MUTEX_INITIALIZER;
}

void push(Queue *q, Product p) {
    if (q->summit < QMAX)
        q->data[q->summit++] = p;
}

Product shift(Queue *q) {

    Product empty; // Empty product
                   // or product retrieved.
    bzero(&empty, sizeof(Product));
    if (q->init == q->summit)
        return empty;

    pthread_mutex_lock(&q->mutex);
    empty = q->data[q->init++];
    pthread_mutex_unlock(&q->mutex);

    return empty;
}
