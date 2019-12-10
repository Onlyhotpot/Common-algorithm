#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void radixSort(int* nums, int length, int radix);

int main()
{
    srand((unsigned)time(NULL));

    while (1)
    {
        printf("Please enter the number of digits you want to enter: ");
        int length;
        scanf("%d", &length);

        // 生成数组
        int* nums = (int*)malloc(length * sizeof(int));
        for (int i = 0; i < length; ++i)
        {
            nums[i] = rand() % 100000;
            printf("%d ", nums[i]);
        }
        printf("\n");

        printf("The radix you want to sorted by: ");
        int radix;
        scanf("%d", &radix);

        radixSort(nums, length, radix);
        //打印出排序后的数组
        printf("RadixSort:\n");
        for (int i = 0; i < length; ++i)
            printf("%d ", nums[i]);
        printf("\n");

        free(nums);
    }
	system("pause");
	return 0;
}

void radixSort(int* nums, int length, int radix)
{
    int max = nums[0];
    for (int i = 1; i < length; ++i)
        if (nums[i] > max)
            max = nums[i];

    // 获取基数为radix的最大数字的长度
    int max_size = 0;
    for (int temp = max; temp > 0; temp /= radix)
        ++max_size;

    // 对每一位数进行稳定性计数排序
    for (int cnt = 1; cnt <= max_size; ++cnt)
    {
        // 获取数组当前位数的值，储存在数组temp中
        int* temp = (int*)malloc(length * sizeof(int));
        for (int i = 0; i < length; ++i)
        {
            temp[i] = nums[i];
            for (int j = 1; j < cnt; ++j)
                temp[i] /= radix;
            temp[i] %= radix;
        }

        // 初始化计数数组并初始化为0
        int* countArray = (int*)malloc(radix * sizeof(int));
        for (int i = 0; i < radix; ++i)
            countArray[i] = 0;


        // 进行基本的计数
        for (int i = 0; i < length; ++i)
            ++countArray[temp[i]];

        // 对计数数组进行变形，后面元素等于前面元素之和
        for (int i = 1; i < 10; ++i)
            countArray[i] += countArray[i-1];

        int *sortedArray = (int*)malloc(length * sizeof(int));
        // 倒序遍历原数组，从计数数组中找到正确的位置，输出到结果数组
        for (int i = length - 1; i >= 0; --i)
            sortedArray[--countArray[temp[i]]] = nums[i];

        // 将排序后的数组复制会原数组
        for (int i = 0; i < length; ++i)
            nums[i] = sortedArray[i];

        free(temp);
        free(countArray);
        free(sortedArray);
    }
}
