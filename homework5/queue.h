#include <stdio.h>
#include <stdlib.h>

#ifndef QUEUE_H
#define QUEUE_H

struct queue;
typedef struct queue* Queue;

struct queue
{
    TreeNode *trees;
    int maxSize;
    int head;
    int tail;
    int length;
};

Queue CreatQueue(int maxSize);
void add(Queue Q, TreeNode Node);
TreeNode poll(Queue Q);
TreeNode peek(Queue Q);
int isEmpty(Queue Q);
int isFull(Queue Q);
void freeQueue(Queue Q);

Queue CreatQueue(int maxSize)
{
    Queue Q = (Queue)malloc(sizeof(struct queue));
    Q->maxSize = maxSize;
    Q->trees = (TreeNode*)malloc(maxSize * sizeof(TreeNode));
    Q->head = 0;
    Q->tail = -1;
    Q->length = 0;
}

void add(Queue Q, TreeNode Node)
{
    if (!isFull(Q))
    {
        ++Q->length;
        Q->tail = (Q->tail + 1) % Q->maxSize;
        Q->trees[Q->tail] = Node;
    }
}

TreeNode poll(Queue Q)
{
    if (!isEmpty(Q))
    {
        --Q->length;
        TreeNode temp = Q->trees[Q->head];
        Q->head = (Q->head + 1) % Q->maxSize;
        return temp;
    }
    return NULL;
}

TreeNode peek(Queue Q)
{
    if (!isEmpty(Q))
    {
        return Q->trees[Q->head];
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
    free(Q->trees);
    free(Q);
}

#endif
