#include<stdio.h>
#include<time.h>.

long long power_2(int x, int n);
long long power_3(int x, int n);

int main()
{
    while (1) {
        printf("please input x and n: ");
        int x = 0, n = 0;
        scanf("%d %d", &x, &n);
        long long res = 0;
        clock_t start_time, end_time;
        start_time = clock();
        for (int i = 0; i < 100000000; ++i)
        {
            res = power_2(x, n);
        }
        end_time = clock();
        printf("power(x,n) = %ld\n", res);
        printf("Execution time of power_2(%d, %d) for 100000000 times was %lf seconds\n"
               ,x ,n , (long double)(1.0*(end_time-start_time)/CLOCKS_PER_SEC));

        res = 0;
        start_time = clock();
        for (int i = 0; i < 100000000; ++i)
        {
            res = power_3(x, n);
        }
        end_time = clock();
        printf("power(x,n) = %ld\n", res);
        printf("Execution time of power_3(%d, %d) for 100000000 times was %lf seconds\n"
               ,x ,n , (long double)(1.0*(end_time-start_time)/CLOCKS_PER_SEC));

        system("pause");
    }
    return 0;
}

long long power_2(int x, int n)
{
    if (0 == n)
        return 1;
    if (1 == n)
        return x;
    if (n%2) return power_2(x*x, n>>1)*x;
    else return power_2(x*x, n>>1);
}

long long power_3(int x, int n)
{
    if (0 == n)
        return 1;
    if (1 == n)
        return x;
    if (2 == n)
        return x*x;
    if (1 == n%3)
        return power_3(x*x*x, n/3)*x;
    if (2 == n%3)
        return power_3(x*x*x, n/3)*x*x;
    return power_3(x*x*x, n/3);
}
