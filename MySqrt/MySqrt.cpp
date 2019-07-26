#include<iostream>
#include<cmath>

double MySqrt(int num)
{
    // Å£¶Ùµü´ú·¨
    double result(num);
    while(fabs(result*result-num) > 1e-10){
        result = result/2+num/(2*result);
    }
    return result;
}
