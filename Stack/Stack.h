#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef STACK_H
#define STACK_H

#define ElementType char
#define ERROR -1
#define SUCCESS 0

struct node;
typedef struct node* Node;
typedef Node Stack;

Stack makeEmpty();
void push(ElementType element, Stack S);
ElementType pop(Stack S);
ElementType top(Stack S);
int isEmpty(Stack S);
void freeStack(Stack S);


struct node
{
    ElementType data;
    struct node *next;
};

Stack makeEmpty()
{
    Stack stack = (Stack)malloc(sizeof(struct node));
    stack->next = NULL;
    return stack;
}

void push(ElementType element, Stack S)
{
    Node temp = (Stack)malloc(sizeof(struct node));
    temp->data = element;
    temp->next = S->next;
    S->next = temp;
}

ElementType pop(Stack S)
{
    ElementType element;
    if (!isEmpty(S))
    {
        Node temp = S->next;
        S->next = temp->next;
        element = temp->data;
        free(temp);
        return element;
    }
    return ERROR;
}

ElementType top(Stack S)
{
    if (!isEmpty(S))
        return S->next->data;
    return ERROR;
}

int isEmpty(Stack S)
{
    return S->next == NULL;
}

void freeStack(Stack S)
{
    Node temp = S;
    while (S)
    {
        temp = S->next;
        free(S);
        S = temp;
    }
}

#endif // STACK_H
