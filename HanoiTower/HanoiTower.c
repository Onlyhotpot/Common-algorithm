#include<stdio.h>
void HanoiTower(int n,char souce,char temp,char target){
    if(1 == n){
        printf("%c->%c\n",souce,target);
        return;
    }
    HanoiTower(n-1,souce,target,temp);
    printf("%c->%c\n",souce,target);
    HanoiTower(n-1,temp,souce,target);
}

int main(){
    printf("Please input the height of the Hanoitower: ");
    int n=1;
    scanf("%d",&n);
    HanoiTower(n,'A','B','C');
    return 0;
}