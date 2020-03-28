#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Cutoff (3)

typedef int ElementType;

void QuickSort(ElementType* nums,int size);
ElementType Median3(ElementType *A, int left, int right);
void Qsort(ElementType *nums, int left, int right);
void InserionSort(ElementType *nums, int length);
void swap(int *a, int *b);

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
        for (int i = 0; i < 10000; ++i)
        {
            QuickSort(nums, length);
        }
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

void QuickSort(int* nums,int size)
{
    Qsort(nums, 0, size - 1);
}

ElementType Median3(ElementType *A, int left, int right)
{
    int center = left + (right - left) / 2;

    if (A[left] > A[center])
        swap(&A[left], &A[center]);
    if (A[left] > A[right])
        swap(&A[left], &A[right]);
    if (A[center] > A[right])
        swap(&A[center], &A[right]);

    swap(&A[center], &A[right - 1]);    // Hide pivot
    return A[right - 1];                // return pivot
}

void Qsort(ElementType *nums, int left, int right)
{
    int i, j;
    ElementType pivot;

    if (left + Cutoff <= right)
    {
        pivot = Median3(nums, left, right);
        i = left;
        j = right - 1;
        while (1)
        {
            while (nums[++i] < pivot);
            while (nums[--j] > pivot);
            if (i < j)
                swap(&nums[i], &nums[j]);
            else
                break;
        }
        swap(&nums[i], &nums[right - 1]);  // Restore pivot

        Qsort(nums, left, i - 1);
        Qsort(nums, i + 1, right);
    }
    else
        InserionSort(nums + left, right - left + 1);
}

void InserionSort(ElementType* nums, int length)
{
    ElementType temp;
    for (int i = 1, j = 0; i < length; ++i)
    {
        temp = nums[i];
        for(j = i; j > 0 && temp < nums[j-1];){
            nums[j] = nums[--j];
        }
        nums[j] = temp;
    }
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
