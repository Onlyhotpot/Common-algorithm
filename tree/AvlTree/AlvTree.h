#include <stdio.h>
#include <stdlib.h>

#ifndef AVLTREE_H
#define AVLTREE_H

#define false 0
#define true 1
#define Max(a, b) a > b ? a : b
typedef int ElementType;
typedef int bool;

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

AvlTree MakeEmpty(ElementType element);
Position Find(ElementType element, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
static int Height(Position P);
static Position SingleRotateWithLeft(Position P);
static Position SingleRotateWithRight(Position P);
static Position DoubleRotateWithLeft(Position P);
static Position DoubleRotateWithRight(Position P);
AvlTree Insert(ElementType element, AvlTree T);
AvlTree Delete(ElementType element, AvlTree T);
ElementType Retrieve(Position P);
void FreeTree(AvlTree T);

struct AvlNode
{
    ElementType element;
    AvlTree left;
    AvlTree right;
    int height;
    bool isDeleted;
};

AvlTree MakeEmpty(ElementType element)
{
    AvlTree T = (AvlTree)malloc(sizeof(struct AvlNode));
    T->element = element;
    T->left = NULL;
    T->right = NULL;
    T->height = 0;
    T->isDeleted = false;
}


Position Find(ElementType element, AvlTree T)
{
    while (T && element != T->element)
    {
        if (element < T->element)
            T = T->left;
        else
            T = T->right;
    }

    return (T && !T->isDeleted) ? T : NULL;
}

Position FindMin(AvlTree T)
{
    if (T)
    {
        while (T->left)
            T = T->left;
        return T;
    }
    return NULL;
}

Position FindMax(AvlTree T)
{
    if (T)
    {
        while (T->right)
            T = T->right;
        return T;
    }
    return NULL;
}

AvlTree Insert(ElementType element, AvlTree T)
{
    if (T == NULL)
    {
        /* Create and return a one-node tree*/
        T = (AvlTree)malloc(sizeof(struct AvlNode));
        if (T == NULL)
            printf("Out of space!!!");
        else
        {
            T->element = element;
            T->left = NULL;
            T->right = NULL;
            T->height = 0;
            T->isDeleted = false;
        }
    }
    else
    if (element < T->element)
    {
        T->left = Insert(element, T->left);
        if (Height(T->left) - Height(T->right) == 2)
            if (element < T->left->element)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
    }
    else
    if (element > T->element)
    {
        T->right = Insert(element, T->right);
        if (Height(T->right) - Height(T->left) == 2)
            if (element > T->right->element)
                T = SingleRotateWithRight(T);
            else
                T = DoubleRotateWithRight(T);
    }
    else
        T->isDeleted = false;

    T->height = Max(Height(T->left), Height(T->right)) + 1;
    return T;
}

static int Height(Position P)
{
    if (P == NULL)
        return -1;
    else
        return P->height;
}

static Position SingleRotateWithLeft(Position K2)
{
    Position K1;

    K1 = K2->left;
    K2->left = K1->right;
    K1->right = K2;

    K2->height = Max(Height(K2->left),Height(K2->right)) + 1;
    K1->height = Max(Height(K1->left),Height(K1->right)) + 1;

    return K1;
}

static Position SingleRotateWithRight(Position K2)
{
    Position K1;

    K1 = K2->right;
    K2->right = K1->left;
    K1->left = K2;

    K2->height = Max(Height(K2->left),Height(K2->right)) + 1;
    K1->height = Max(Height(K1->left),Height(K1->right)) + 1;

    return K1;
}

static Position DoubleRotateWithLeft(Position P)
{
    P->left = SingleRotateWithRight(P->left);

    return SingleRotateWithLeft(P);
}

static Position DoubleRotateWithRight(Position P)
{
    P->right = SingleRotateWithLeft(P->right);

    return SingleRotateWithRight(P);
}

AvlTree Delete(ElementType element, AvlTree T)
{
    Position P = Find(element, T);
    if (P)
        P->isDeleted = true;
    return T;
}

ElementType Retrieve(Position P)
{
    return P->element;
}

void FreeTree(AvlTree T)
{
    if (!T)
        return
    FreeTree(T->left);
    FreeTree(T->right);
    free(T);
}

#endif // AVLTREE_H
