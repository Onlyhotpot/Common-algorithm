#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 1000
#define M 100

struct node;
typedef struct node* LinkList;
typedef struct node* Node;

void makeOrderedPolynomial(LinkList A);
void makeNotOrderedPolynomial(LinkList A);
void addWithOrder(LinkList A, int modulus, int exponent);
void addWithoutOrder(LinkList A, int modulus, int exponent);
void printPolynomial(LinkList A);
void freeList(LinkList A);
LinkList multiplyOrderedPolynomial(LinkList A, LinkList B);
LinkList multiplyNotOrderedPolynomial(LinkList A, LinkList B);

struct node
{
    int modulus;    // 系数
    int exponent;   // 指数
    Node next;
};

int main()
{
    srand((unsigned)time(NULL));

    LinkList A = (LinkList)malloc(sizeof(struct node));
    A->next = NULL;
    LinkList B = (LinkList)malloc(sizeof(struct node));
    B->next = NULL;
    int a[N];
    for (int i = 0; i < N; ++i)
        a[i] = rand();

    int b[M];
    for (int i = 0; i < M; ++i)
        b[i] = rand();

    // makeOrderedPolynomial(A);
    for (int i = 0; i < N; ++i)
        addWithOrder(A, 1, a[i]);
    //printf("The polynomial A: ");
    //printPolynomial(A);

    // makeOrderedPolynomial(B);
    for (int i = 0; i < M; ++i)
        addWithOrder(B, 1, b[i]);
    //printf("The polynomial B: ");
    //printPolynomial(B);

    LinkList C;
    clock_t start, end;
    start = clock();
    for (int i = 0; i < 100; ++i)
        C = multiplyOrderedPolynomial(A, B);
    end = clock();

    //printf("The polynomial C: ");
    //printPolynomial(C);
    printf("Execution time was %lf seconds.\n", (long double)1.0*(end - start)/CLOCKS_PER_SEC);

    freeList(A);
    freeList(B);
    freeList(C);

    printf("\n");
    A = (LinkList)malloc(sizeof(struct node));
    A->next = NULL;
    B = (LinkList)malloc(sizeof(struct node));
    B->next = NULL;

    // makeNotOrderedPolynomial(A);
    for (int i = 0; i < N; ++i)
        addWithoutOrder(A, 1, a[i]);
    //printf("The polynomial A: ");
    //printPolynomial(A);

    //makeNotOrderedPolynomial(B);

    for (int i = 0; i < M; ++i)
        addWithoutOrder(B, 1, b[i]);
    //printf("The polynomial B: ");
    //printPolynomial(B);

    start = clock();
    C = multiplyNotOrderedPolynomial(A, B);
    end = clock();

    //printf("The polynomial C: ");
    //printPolynomial(C);
    printf("Execution time was %lf seconds.\n", (long double)1.0*(end - start)/CLOCKS_PER_SEC);

    freeList(A);
    freeList(B);
    freeList(C);

    system("pause");
    return 0;
}

void makeOrderedPolynomial(LinkList A)
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

void makeNotOrderedPolynomial(LinkList A)
{
    int modulus, exponent;
    char flag;
    do
    {
        printf("Please input the modulus and exponent of the polynomial: ");
        scanf("%d%d", &modulus, &exponent);
        getchar();
        addWithoutOrder(A, modulus, exponent);
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

void addWithoutOrder(LinkList A, int modulus, int exponent)
{
    while(A->next && A->next->exponent != exponent)
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

LinkList multiplyOrderedPolynomial(LinkList A, LinkList B)
{
    LinkList res = (LinkList)malloc(sizeof(struct node));
    res->next = NULL;
    while (A->next)
    {
        A = A->next;
        LinkList temp = B;
        LinkList flag = res;
        int modulus, exponent;
        while (temp->next)
        {
            temp = temp->next;
            modulus = temp->modulus * A->modulus;
            exponent = temp->exponent + A->exponent;
            while(flag->next && flag->next->exponent < exponent)
                flag = flag->next;
            if (flag->next && flag->next->exponent == exponent)
            {
                flag = flag->next;
                flag->modulus += modulus;
            }
            else
            {
                Node temp = (Node)malloc(sizeof(struct node));
                temp->exponent = exponent;
                temp->modulus = modulus;
                temp->next = flag->next;
                flag->next = temp;
                flag = temp;
            }
        }
    }
    return res;
}

LinkList multiplyNotOrderedPolynomial(LinkList A, LinkList B)
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
            addWithoutOrder(res, A->modulus * temp->modulus, A->exponent + temp->exponent);
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
