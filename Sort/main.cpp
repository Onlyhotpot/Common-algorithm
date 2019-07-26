#include <iostream>
void SelectSort(int* nums,int size);
void BubbleSort(int* nums,int size);
void QuickSort(int* nums,int size);
void ShellSort(int* nums,int size);
void InsertSort(int* nums,int size);

int main()
{
    int size;
    std::cout << "Please input the size of array: " << std::endl;
    std::cin >> size;
    std::cout << "Please input the numbers of array: " << std::endl;
    int *nums = new int(size);
    for(int i = 0; i < size; i++){
        std::cin >> nums[i];
    }

//    InsertSort(nums,size);
//    std::cout << "The array after insert sort is: " << std::endl;
//    for(int i = 0; i < size; i++){
//        std::cout << nums[i] << " ";
//    }
//    std::cout << std::endl;
//
//    QuickSort(nums,size);
//    std::cout << "The array after quick sort is: " << std::endl;
//    for(int i = 0; i < size; i++){
//        std::cout << nums[i] << " ";
//    }
//    std::cout << std::endl;
//
//    SelectSort(nums,size);
//    std::cout << "The array after select sort is: " << std::endl;
//    for(int i = 0; i < size; i++){
//        std::cout << nums[i] << " ";
//    }
//    std::cout << std::endl;

    BubbleSort(nums,size);
    std::cout << "The array after bubble sort is: " << std::endl;
    for(int i = 0; i < size; i++){
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    delete[] nums;
    return 0;
}
