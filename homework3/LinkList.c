#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node;
typedef struct node* LinkList;
typedef struct node* Node;

void add(LinkList A, int modulus, int exponent);
void multiply(LinkList A, LinkList B);
void printPolynomial(LinkList A);
void freeList(LinkList A);

int main()
{
    LinkList A = (LinkList)malloc(sizeof(struct node));
    A->next = 0;
    printf("Please input the modulus and exponent of polynomial A: ");
}

struct node
{
    int modulus;    // 系数
    int exponent;   // 指数
    LinkList next;
};

void add(LinkList A, int modulus, int exponent)
{
    while(A->next && A->next->exponent < exponent)
        A = A->next;
    if (A->next && A->next->exponent == exponent)
    {
        A = A->next;
        A->modulus += modulus;
    }
    else
    {
        Node temp = (Node)malloc(sizeof(struct note));
        temp->exponent = exponent;
        temp->modulus = modulus;
        temp->next = A->next;
        A->next = temp;
    }
}

void multiply(LinkList A, LinkList B)
{

}

void printPolynomial(LinkList A)
{
    while (A->next)
    {
        A  = A->next;
        printf(" %dx^%d ", A->modulus, A->exponent);
        if (A->next)
            printf("+");
    }
}

void freeList(LinkList A)
{
    Node temp;
    while (A)
    {
        temp = A;
        A = A->next;
        free(temp);
    }
}
