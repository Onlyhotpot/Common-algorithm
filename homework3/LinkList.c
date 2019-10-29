#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node;
typedef struct node* LinkList;
typedef struct node* Node;

void makePolynomial(LinkList A);
void addWithOrder(LinkList A, int modulus, int exponent);
void printPolynomial(LinkList A);
void freeList(LinkList A);
LinkList multiply(LinkList A, LinkList B);

struct node
{
    int modulus;    // 系数
    int exponent;   // 指数
    Node next;
};

int main()
{
    LinkList A = (LinkList)malloc(sizeof(struct node));
    A->next = NULL;
    LinkList B = (LinkList)malloc(sizeof(struct node));
    B->next = NULL;

    makePolynomial(A);
    printPolynomial(A);

    makePolynomial(B);
    printPolynomial(B);

    LinkList C;
    C = multiply(A, B);
    printPolynomial(C);

    freeList(C);
    freeList(A);
    freeList(B);
    return 0;
}

void makePolynomial(LinkList A)
{
    int modulus, exponent;
    char flag;
    do
    {
        printf("Please input the modulus and exponent of the polynomial: ");
        scanf("%d%d", &modulus, &exponent);
        getchar();
        addWithOrder(A, modulus, exponent);
        printf("Do you want to add another note? (y/n): ");
        flag = getchar();
    }while(flag != 'n');
}

void addWithOrder(LinkList A, int modulus, int exponent)
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
        Node temp = (Node)malloc(sizeof(struct node));
        temp->exponent = exponent;
        temp->modulus = modulus;
        temp->next = A->next;
        A->next = temp;
    }
}

LinkList multiply(LinkList A, LinkList B)
{
    LinkList res = (LinkList)malloc(sizeof(struct node));
    res->next = NULL;
    while (A->next)
    {
        A = A->next;
        LinkList temp = B;
        while (temp->next)
        {
            temp = temp->next;
            addWithOrder(res, A->modulus * temp->modulus, A->exponent + temp->exponent);
        }
    }
    return res;
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
    printf("\n");
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
