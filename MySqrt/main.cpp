#include <iostream>
double MySqrt(int num);

int main()
{
    std::cout << "Input number: " ;
    int num;
    while(std::cin >> num){
        if(num < 0){
            std::cout << "Input error , please input again: ";
        }else{
            break;
        }
    }
    std::cout << "Sqrt(" << num << ") is " << MySqrt(num) << std::endl;
    return 0;
}
