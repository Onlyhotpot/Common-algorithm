#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void radixSort(int* array, int length)；

int main()
{
    srand((unsigned)time(NULL));

    // 生成随机测试列表 0-99
    int test_list[20];
    int test_list_length = sizeof(test_list) / sizeof(int);

    printf("测试列表： \n");
    for (int i = 0; i < test_list_length; i++)
    {
        test_list[i] = rand() % 100;
        printf("%d ", test_list[i]);
    }
    printf("\n");

    // 普通基数排序
    radixSort(test_list, test_list_length);
    printf("普通基数排序结果： \n");
    for (int i = 0; i < test_list_length; i++)
    {
        printf("%d ", test_list[i]);
    }
    printf("\n");

    system("pause");
    return 0;
}

void radixSort(int* array, int length)
{
    // 排序结果数组，用于存储每一次按为排序的临时结果
    int *sortedArray = (int*)malloc(sizeof(int) * length);
}
