#include<stdio.h>
#include<time.h>

int SquareSum(int n);

int main()
{
    printf("Please input the number of n: ");
    int n;
    scanf("%d",&n);

    clock_t start_time, end_time;

    start_time = clock();
    for (int i = 1; i <= n; ++i)
    {
        printf("The sum of squares from 1 to %d is: %d\n", i, SquareSum(i));
    }
    end_time = clock();
    printf("Execution time was %lu seconds\n",(long)((end_time - start_time)/CLOCKS_PER_SEC));
    return 0;
}

int SquareSum(int n)
{
    return n * (n + 1) * (2 * n +1) / 6;
}