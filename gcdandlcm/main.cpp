#include <iostream>

int gcd(int num1,int num2); // �����Լ��
int lcm(int num1,int num2); // ����С������

int main()
{
    int num1,num2;
    std::cout << "Please input number1 and number2: ";
    std::cin >> num1 >> num2;
    std::cout << "The maximum common divisor of " << num1 << " and " << num2 << " is  " << gcd(num1,num2) << std::endl;
    std::cout << "The least common multiple of " << num1 << " and " << num2 << " is  " << lcm(num1,num2) << std::endl;
    return 0;
}
