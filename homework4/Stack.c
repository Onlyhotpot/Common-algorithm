#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define ERROR -1
#define SUCCESS 0
#define ElementType char

struct node;
typedef struct node* Node;
typedef Node Stack;

Stack makeEmpty();
void push(ElementType element, Stack S);
ElementType pop(Stack S);
ElementType top(Stack S);
int isEmpty(Stack S);
void freeStack(Stack S);
void changeToSuffixExpression(char *expression);

int main()
{
    while (1)
    {
        printf("Please input the arithmetic expression: ");
        char expression[20];
        scanf("%s", expression);
        clock_t start, end;
        start = clock();
        for (int i = 0; i < 1; ++i)
        {
            changeToSuffixExpression(expression);
        }
        end = clock();
        printf("The suffix expression is: %s\n", expression);
        printf("Execution time was %lf seconds.\n", (long double)(1.0*(end - start)/CLOCKS_PER_SEC));
    }
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

void changeToSuffixExpression(char* expression)
{
    int length = strlen(expression);
    Stack stack = makeEmpty();
    int index = 0;
    for (int i = 0; i < length; ++i)
    {
        if (expression[i] >= '0' && expression[i] <= '9')
        {
            expression[index] = expression[i];
            ++index;
            continue;
        }
        switch(expression[i])
        {
            case '+':
            case '-':
                while (!isEmpty(stack) && top(stack) != '(')
                {
                    expression[index] = pop(stack);
                    ++index;
                }
                push(expression[i], stack);
                break;

            case '*':
            case '/':
                while (!isEmpty(stack) && (top(stack) == '*' || top(stack) == '/'))
                {
                    expression[index] = pop(stack);
                    ++index;
                }
                push(expression[i], stack);
                break;

            case '(':
                push(expression[i], stack);
                break;

            case ')':
                while (!isEmpty(stack) && top(stack) != '(')
                {
                    expression[index] = pop(stack);
                    ++index;
                }
                pop(stack);
                break;
        }
    }
    while (index < length)
    {
        expression[index] = pop(stack);
        ++index;
    }
    freeStack(stack);
}
