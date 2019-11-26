#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int Josephus(int n, int m);

int main()
{
    while (1)
    {
        printf("Please input the n and m: ");
        int n, m;
        scanf("%d%d", &n, &m);
        int res;
        clock_t start, end;

        start = clock();
        for (int i = 0; i < 1000000; ++i)
            res = Josephus(n, m);
        end = clock();

        printf("The one who is alive is %d.\n", res);
        printf("Execution time of 1000000 times was %lf seconds.\n",
                (long double)(1.0*(end - start)/CLOCKS_PER_SEC));
    }
    system("pause");
    return 0;
}

int Josephus(int n, int m)
{
    int* link = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; ++i)
        link[i] = (i + 1)%n;
    int header = n - 1;
    while (link[header] != header)
    {
        int temp = m%(n++);
        for (int i = 1; i < temp; ++i)
            header = link[header];
        link[header] = link[link[header]];
    }
    free(link);
    return header + 1;
}