#include <iostream>

int Fibonacci(int n)
{
    // 递归解法（不推荐)
    // return n == 1 || n == 2 ? 1 : Fibonacci(n-1)+Fibonacci(n-2);

    int a = 1,b = 1;
    int result = 1;
    for (int i = 2; i < n; i++){
        result = a + b;
        a = b;
        b = result;
    }
    return result;
}
