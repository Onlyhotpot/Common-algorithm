#include<stdio.h>
#define Cutoff (3)
typedef int ElementType;

void QuickSort(int* nums,int size);
ElementType Median3(ElementType *A, int left, int right);
void Qsort(ElementType *nums, int left, int right);
void InserionSort(ElementType *nums, int length);
void swap(int *a, int *b);

void QuickSort(int* nums,int size)
{
    Qsort(nums, 0, size - 1);
}

ElementType Median3(ElementType *A, int left, int right)
{
    int center = (left + right) / 2;

    if (A[left] > A[right])
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
        for (j = i; j > 0; --j)
            nums[j] = nums[j - 1];
        nums[j] = temp;
    }
}

void swap(int* a, int* b)
{
    *a = *a^*b;
    *b = *a^*b;
    *a = *a^*b;
}

int main()
{
    return 0;
}
