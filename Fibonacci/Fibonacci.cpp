#include <iostream>

int Fibonacci(int n)
{
    return n == 1 || n == 2 ? 1 : Fibonacci(n-1)+Fibonacci(n-2);
}
