#include "queue.h"
#include <string.h>

void init(Queue *q) { q->init = q->summit = 0; }

void push(Queue *q, Product p) {
    if (q->summit < QMAX)
        q->data[q->summit++] = p;
}

Product shift(Queue *q) {

    Product empty;
    bzero(&empty, sizeof(Product));
    if (q->init == q->summit)
        return empty;

    return q->data[q->init++];
}
