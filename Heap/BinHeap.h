#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#ifndef BINHEAP_H
#define BINHEAP_H

#define false 0
#define true 1

struct int ElementType;
struct int bool;
struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;

PriorityQueue Initialize(int MaxElements);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType element, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
bool IsEmpty(PriorityQueue H);
bool IsFull(PriorityQueue H);

struct HeapStruct
{
    int Capacity;
    int Size;
    ElementType* elements;
};

PriorityQueue Initialize(int MaxElements)
{
    PriorityQueue H;

    H = (PriorityQueue)malloc(sizeof(struct HeapStruct));
    H->Capacity = MaxElements;
    H->elements = (ElementType*)malloc((MaxElements + 1) * sizeof(ElementType));
    H->Size = 0;
    H->elements[0] = INT_MIN;

    return H;
}

void Destroy(PriorityQueue H)
{
    free(H->elements);
    free(H);
}

void MakeEmpty(PriorityQueue H)
{
    H->Size = 0;
}

void Insert(ElementType element, PriorityQueue H)
{
    int i;

    if (IsFull(H))
    {
        printf("The Heap is already full");
        return;
    }

    for (i = ++H->Size; H->elements[i/2] > element; i /= 2)
        H->elements[i] = H->elements[i/2];
    H->elements[i] = element;
}

ElementType DeleteMin(PriorityQueue H)
{
    int i, child;
    ElementType MinElement, LastElement;

    if (IsEmpty(H))
    {
        printf("The heap is empty!!");
        return H->elements[0];
    }
    MinElement = H->elements[1];
    LastElement = H->elements[H->Size--];

    for (i = 1; i * 2 <= H->Size; i = child)
    {
        // find smaller child
        child = 2 * i;
        if (child != H->Size && H->elements[child + 1] < H->elements[child])
            ++child;

        // Percolate one level
        if (LastElement > H->elements[child])
            H->elements[i] = H->elements[child];
        else
            break;
    }
    H->elements[i] = LastElement;
    return MinElement;
}

ElementType FindMin(PriorityQueue H)
{
    return H->elements[1];
}

bool IsEmpty(PriorityQueue H)
{
    return 0 == H->Size;
}

bool IsFull(PriorityQueue H)
{
    return H->Capacity == H->Size;
}

#endif // BINHEAP_H
