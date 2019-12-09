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
void preOrderTraversal(AvlTree T);
void midOrderTraversal(AvlTree T);
void postOrderTraversal(AvlTree T);
void FreeTree(AvlTree T);

struct AvlNode
{
    ElementType element;
    AvlTree left;
    AvlTree right;
    int height;
    bool isDeleted;
};

#endif // AVLTREE_H
