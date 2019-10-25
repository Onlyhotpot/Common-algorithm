#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ERROR -1
#define SUCCESS 0
#define ElementType char

struct node;
typedef struct node* Node;
typedef Node Stack;

Stack makeEmpty();
void push(ElementType element, Stack S);
ElementType pop(Stack S);
int isEmpty(Stack S);
void freeStack(Stack S);
void changeToSuffixExpression(char *expression);

int main()
{
    printf("Please input the arithmetic expression: ");
    char expression[20];
    scanf("%s", expression);
    changeToSuffixExpression(expression);
    printf("%s\n", expression);
    system("pause");
    return 0;
}

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

void changeToSuffixExpression(char* expression)
{
    int length = strlen(expression);
    // remove excess space
    for (int i = 0; i < length; ++i)
    {
        if (expression[i] == ' ')
        {
            for (int j = i; j < length; ++j)
                expression[j] = expression[j+1];
            --length;
        }
    }

}
