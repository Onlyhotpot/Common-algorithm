#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void countSort(int* nums, int length);

int main()
{
    srand((unsigned)time(NULL));
    printf("Please input the size of the array: ");
    int length;
    scanf("%d", &length);
    int *nums = (int*)malloc(length * sizeof(int));
    for (int i = 0; i < length; ++i)
    {
        nums[i] = rand() % 99;
        printf("%d ", nums[i]);
    }
    printf("\n");
    countSort(nums, length);
    for (int i = 0; i < length; ++i)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    free(nums);

    system("pause");
    return 0;
}

// 稳定版计数排序
void countSort(int* array, int length)
{
    int max = array[0];
    int min = array[0];
    for (int i = 1; i < length; ++i)
    {
        if (array[i] > max)
            max = array[i];
        if (array[i] < min)
            min = array[i];
    }

    int d = max - min + 1;
    int* countArray = (int*)malloc(sizeof(int) * d);
    // 将数组元素都初始化为0
    for (int i = 0; i < d; ++i)
    {
        countArray[i] = 0;
    }
    // 进行基本的计数
    for (int i = 0; i < length; ++i)
    {
        ++countArray[array[i] - min];
    }

    // 对计数数组进行变形，后面元素等于前面元素之和
    for (int i = 1; i < d; ++i)
    {
        countArray[i] += countArray[i-1];
    }

    int *sortedArray = (int*)malloc(length * sizeof(int));
    // 倒序遍历原数组，从计数数组中找到正确的位置，输出到结果数组
    for (int i = length - 1; i >= 0; --i)
    {
        sortedArray[--countArray[array[i] - min]] = array[i];
    }

    for (int i = 0; i < length; ++i)
    {
        array[i] = sortedArray[i];
    }
    free(countArray);
    free(sortedArray);
}
