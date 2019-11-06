#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Stack.h"

#define true 1
#define false 0

void CreateStrData();
void changeToSuffixExpression(char *expression);

int main()
{
    while (1)
    {
        printf("Please input the size you want of the expression: ");
        int n;
        scanf("%d", &n);
        char* expression;
        expression = (char*)malloc((2 * n ) * sizeof(char));
        CreateStrData(expression, 2 * n - 1);
        expression[2 * n - 1] = '\0';
        printf("%s\n", expression);

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

void CreateStrData(char* theStr, int n) {

    srand((unsigned)time(NULL));

    int whetherAddNum = true;
    int khNum = 1;
    char fh[5] = {'+', '-', '*', '/'};
    int tmod = 11;

    for (int i = 0; i < n; i++) {
        if (whetherAddNum) {
            if (rand() % tmod == 0 && n - i > khNum) {
                khNum++;
                theStr[i] = '(';
            } else {
                theStr[i] = rand() % 26 + 'a';
                whetherAddNum = false;
            }
        } else {
            if (khNum > 1 && (rand() % tmod == 0 || n - i <= khNum)) {
                khNum--;
                theStr[i] = ')';
                } else {
                theStr[i] = fh[rand() % 4];
                whetherAddNum = true;
            }
        }
    }
}

void changeToSuffixExpression(char* expression)
{
    int length = strlen(expression);
    Stack stack = makeEmpty();
    int index = 0;
    for (int i = 0; i < length; ++i)
    {
        if (expression[i] >= 'a' && expression[i] <= 'z')
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
