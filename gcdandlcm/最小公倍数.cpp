#include<iostream>
int gcd(int num1,int num2);

int lcm(int num1,int num2)
{
    return num1*num2/gcd(num1,num2);
}
