#include<stdio.h>
#include<time.h>

long long fib(int n);

int main()
{
    printf("Please input n: ");
    int n;
    scanf("%d",&n);

    clock_t start_time, end_time;
    start_time = clock();
    for (int i = 0; i < 10000; ++i)
    {
        printf("fib(%d) = %lld\n", n, fib(n));
    }
    end_time = clock();
    printf("Execution time was %lu seconds", (long)(end_time - start_time)/CLOCKS_PER_SEC);
    return 0;
}

long long fib(int n)
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
