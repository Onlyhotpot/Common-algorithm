#include<stdio.h>
int pow(int num, int n);
int main()
{
    int num,n;
    scanf("%d %d",&num,&n);
    printf("pow(num,n) = %d\n", pow(num,n));
}