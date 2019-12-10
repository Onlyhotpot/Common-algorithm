#include<stdio.h>
#include<stdlib.h>

int Josephus(int n, int m);

int main()
{
    printf("Please input the n and m: ");
    int n, m;
    scanf("%d%d", &n, &m);
    int res;

    res = Josephus(n, m);

    printf("The one who is alive is %d.\n", res);

    system("pause");
    return 0;
}

int Josephus(int n, int m)
{
    int* link = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 0; i < n; ++i)
        link[i] = i + 1;
    link[n] = 1;
    int header = n;
    while (link[header] != header)
    {
        for (int i = 1; i < m; ++i)
            header = link[header];
        printf("%d ", link[header]);
        link[header] = link[link[header]];
    }
    free(link);
    return header;
}
