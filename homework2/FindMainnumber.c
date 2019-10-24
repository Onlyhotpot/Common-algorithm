#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define NO_MAJ_ELE -1

int majEle_recursive(int *nums, int size);
int majEle_loop(int *nums, int size);
void swap(int* a, int* b);

int main()
{
    while (1)
    {
        printf("Please input the size of numbers: ");
        int size;
        scanf("%d", &size);
        printf("Input numbers: ");
        int* nums = (int*)malloc(size * sizeof(int));
        for (int i = 0; i < size; ++i)
        {
            scanf("%d", nums + i);
        }
        int majNumber;
        clock_t start,end;

        start = clock();
        for (int i = 0; i < 100000000; ++i)
            majNumber = majEle_loop(nums, size);
        end = clock();
        if (majNumber == NO_MAJ_ELE)
        {
            printf("There is no major number.\n");
        }
        else
        {
            printf("The major number is %d .\n", majNumber);
        }
        printf("Execution time of majEle_loop 100000000 times was %lf seconds\n",
                (long double)(1.0*(end - start)/CLOCKS_PER_SEC));

        start = clock();
        for (int i = 0; i < 100000000; ++i)
            majNumber = majEle_recursive(nums, size);
        end = clock();
        if (majNumber == NO_MAJ_ELE)
        {
            printf("There is no major number.\n");
        }
        else
        {
            printf("The major number is %d .\n", majNumber);
        }
        printf("Execution time of majEle_recursive 100000000 times was %lf seconds\n",
                (long double)(1.0*(end - start)/CLOCKS_PER_SEC));
    }

    system("pause");
    return 0;
}

int majEle_recursive(int* nums, int size)
{
    if (0 == size)
        return NO_MAJ_ELE;
    if (1 == size)
        return nums[0];
    int k = size / 2;
    int count = 0;
    for (int i = 0; i < k; ++i)
    {
        if (nums[2*i] == nums[2*i + 1])
        {
            swap(&nums[count], &nums[2*i+1]);
            ++count;
        }
    }

    int maj = majEle_recursive(nums, count);
    if (size%2)
    {
        if (maj == NO_MAJ_ELE)
            maj =  nums[size-1];
    }
    count = 0;
    for (int i = 0; i < size; ++i) // 判断maj是不是主要元
    {
        if (maj == nums[i])
            ++count;
    }
    if (count > size/2)
    {
        return maj;
    }
    else
    {
        return NO_MAJ_ELE;
    }
}

void swap(int* a, int* b)
{
    *a = *a^*b;
    *b = *a^*b;
    *a = *a^*b;
}

int majEle_loop(int* nums, int size)
{
    for (int i = 0, k = size / 2, count = 0; i < k; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (nums[j] == nums[i])
                ++count;
            if (count > k)
                return nums[j];
        }
    }
    return NO_MAJ_ELE;
}
