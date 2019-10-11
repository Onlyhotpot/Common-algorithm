#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void HanoiTower(int n ,char souce ,char temp ,char target);

int main()
{
    printf("Please input the height of the Hanoitower: ");
    int n = 1;
    scanf("%d",&n);

    clock_t start_time, end_time;

    start_time = clock();
    HanoiTower(n,'A','B','C');
    end_time = clock();
    printf("Execution time was %lu seconds\n",(long)((end_time - start_time)/CLOCKS_PER_SEC));
    return 0;
}

void HanoiTower(int n,char souce,char temp,char target)
{
    if(1 == n)
    {
        printf("%c->%c\n",souce,target);
        return;
    }
    
    HanoiTower(n-1,souce,target,temp);
    printf("%c->%c\n",souce,target);
    HanoiTower(n-1,temp,souce,target);
}