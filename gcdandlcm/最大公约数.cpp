#include<iostream>
int gcd(int num1,int num2)
{
    // 保持num1>num2
    if(num1 < num2){
        // 交换num1与num2的方法
        num1 ^= num2;
        num2 ^= num1;
        num1 ^= num2;
    }
    while(num2){
        num1 %= num2;
        num1 ^= num2;
        num2 ^= num1;
        num1 ^= num2;
    }
    return num1;
}
