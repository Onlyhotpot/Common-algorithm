#include<stdio.h>
#include<time.h>

int SquareSumByIteration(int n);
int SquareSumByFormula(int n);
int main()
{
    printf("Please input the number of n: ");
    int n;
    scanf("%d",&n);

    clock_t start_time, end_time;

    int res = 0;
    start_time = clock();
    for (int i = 1; i <= 10000000; ++i)
    {
        res = SquareSumByIteration(n);
    }
    end_time = clock();
    printf("The sum of squares by iteration from 1 to %d is: %d\n", n, res);
    printf("Execution time used by SquareSumByIteration(n) 10000000 was %lf seconds\n"
           ,(long double)(1.0*(end_time - start_time)/CLOCKS_PER_SEC));

    res = 0;
    start_time = clock();
    for (int i = 1; i <= 10000000; ++i)
    {
        res = SquareSumByFormula(n);
    }
    end_time = clock();
    printf("The sum of squares by formula from 1 to %d is: %d\n", n, res);
    printf("Execution time used by SquareSumByFormula(n) 10000000 was %lf seconds\n"
           ,(long double)(1.0*(end_time - start_time)/CLOCKS_PER_SEC));


    system("pause");
    return 0;
}

int SquareSumByIteration(int n)
{
    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        res += i * i;
    }
    return res;
}

int SquareSumByFormula(int n)
{
    return n * (n + 1) * (2 * n +1) / 6;
}
