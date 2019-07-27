#include <iostream>
int Fibonacci(int n);

int main()
{
    std::cout << "Please input n: ";
    int n;
    std::cin >> n;
    std::cout << "Fibonacci(" << n << ") is " << Fibonacci(n) << std::endl;
    return 0;
}
