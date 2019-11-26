#include <stdio.h>
#include <stdlib.h>

#ifndef QUEUE_H
#define QUEUE_H

typedef int ElementType;
struct queue;
typedef struct queue* Queue;

struct queue
{
    ElementType *elements;
    int maxSize;
    int head;
    int tail;
    int length;
};

Queue CreateQueue(int maxSize);
void enqueue(Queue Q, ElementType Node);
ElementType dequeue(Queue Q);
ElementType peek(Queue Q);
int isEmpty(Queue Q);
int isFull(Queue Q);
void freeQueue(Queue Q);

Queue CreateQueue(int maxSize)
{
    Queue Q = (Queue)malloc(sizeof(struct queue));
    Q->maxSize = maxSize;
    Q->elements = (ElementType*)malloc(maxSize * sizeof(ElementType));
    Q->head = 0;
    Q->tail = -1;
    Q->length = 0;
}

void enqueue(Queue Q, ElementType Node)
{
    if (!isFull(Q))
    {
        ++Q->length;
        Q->tail = (Q->tail + 1) % Q->maxSize;
        Q->elements[Q->tail] = Node;
    }
}

ElementType dequeue(Queue Q)
{
    if (!isEmpty(Q))
    {
        --Q->length;
        ElementType temp = Q->elements[Q->head];
        Q->head = (Q->head + 1) % Q->maxSize;
        return temp;
    }
    return NULL;
}

ElementType peek(Queue Q)
{
    if (!isEmpty(Q))
    {
        return Q->elements[Q->head];
    }
    return NULL;
}

int isEmpty(Queue Q)
{
    return Q->length == 0;
}

int isFull(Queue Q)
{
    return Q->length == Q->maxSize;
}

void freeQueue(Queue Q)
{
    free(Q->elements);
    free(Q);
}

#endif
