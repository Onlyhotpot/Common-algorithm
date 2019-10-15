#include<stdio.h>
#include<time.h>

long long FibByIteration(int n);
long long FibByRecursion(int n);
int main()
{
    printf("Please input n: ");
    int n;
    scanf("%d",&n);

    clock_t start_time, end_time;
    long long res = 0;

    start_time = clock();
    for (int i = 0; i < 1000000; ++i)
    {
        res = FibByIteration(n);
    }
    end_time = clock();
    printf("FibByIteration(%d) = %lld\n", n, res);
    printf("Execution time used by FibByIteration(%d) 1000000 times was %lf seconds\n"
           ,n , (long double)(end_time - start_time)/CLOCKS_PER_SEC);

    res = 0;
    start_time = clock();
    res = FibByRecursion(n);
    end_time = clock();
    printf("FibByRecursion(%d) = %lld\n", n, res);
    printf("Execution time used by FibByRecursion(%d) 1 time was %lf seconds\n"
           ,n , (long double)(end_time - start_time)/CLOCKS_PER_SEC);
    return 0;
}

long long FibByIteration(int n)
{
    long long res = 1;
    long long pre = 1, cul = 1;
    for (int i = 2; i < n; ++i)
    {
        res = pre + cul;
        pre = cul;
        cul = res;
    }
    return res;
}

long long FibByRecursion(int n)
{
    if(0 == n || 1 == n)
        return 1;
    return FibByRecursion(n-1) + FibByRecursion(n-2);
}
