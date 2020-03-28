#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InsertSort(int* nums, int size);

int main()
{
    srand((unsigned)time(NULL));

    while (1)
    {
        printf("Please input the size of the array: ");
        int length;
        scanf("%d", &length);
        int *nums = (int*)malloc(length * sizeof(int));
        for (int i = 0; i < length; ++i)
        {
            nums[i] = rand() % 10000;
            // printf("%d ", nums[i]);
        }
        // printf("\n");

        clock_t start, end;
        start = clock();
        // for (int i = 0; i < 10000; ++i)
        // {
            InsertSort(nums, length);
        // }
        end = clock();

        printf("Execution time was %.3lf seconds\n", (long double)1.0*(end - start) / CLOCKS_PER_SEC);


        for (int i = 0; i < length; ++i)
        {
            printf("%d ", nums[i]);
        }
        printf("\n");


        free(nums);
    }

    system("pause");
    return 0;
}

void InsertSort(int* nums,int size){
    for(int i = 1, j = 0; i < size; ++i){
        int temp = nums[i];
        for(j = i; j > 0 && temp < nums[j-1];){
            nums[j] = nums[--j];
        }
        nums[j] = temp;
    }
}
