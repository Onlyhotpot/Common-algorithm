#include<iostream>
#include<cmath>

double MySqrt(int num)
{
    // ţ�ٵ�����
    double result(num);
    while(fabs(result*result-num) > 1e-10){
        result = result/2+num/(2*result);
    }
    return result;
}
