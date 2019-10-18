#include<stdio.h>
#include<time.h>
long power(int x, int n);

int main()
{
    printf("please input x and n: ");
    int x = 0, n = 0;
    scanf("%d %d", &x, &n);
    long res = 0;
    clock_t start_time, end_time;
    start_time = clock();
    for (int i = 0; i < 100000000; ++i)
    {
        res = power(x,n);
    }
    end_time = clock();
    printf("power(x,n) = %ld\n", res);
    printf("Execution time was %lf seconds\n", (long double)(1.0*(end_time-start_time)/CLOCKS_PER_SEC));

    system("pause");
    return 0;
}

long power(int x, int n)
{
    if (0 == n)
        return 1;
    if (n%2) return power(x*x, n/2)*x;
    else return power(x*x, n/2);
}
