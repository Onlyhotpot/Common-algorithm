#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Merge(int*,int,int,int);
void MergeSort(int*,int,int);

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
            MergeSort(nums, 0, length-1);
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

void MergeSort(int*p,int low,int high)
{
	int mid = low + (high - low)/2;
	if (low <high)
	{
		MergeSort(p,low,mid);
		MergeSort(p,mid+1,high);
		Merge(p,low,mid,high);
	}
}

void Merge(int *p,int low,int mid,int high)
{
	int i,k;
	int* temp = (int*)malloc((high - low + 1)*sizeof(int));//合并空间
	int start1 = low;
	int end1 = mid;
	int start2 = mid+1;
	int end2 = high;
	//比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置
	for (k = 0;start1<=end1 && start2<=end2;k++)
	{
		if (p[start1]<p[start2])
			temp[k] = p[start1++];
		else
			temp[k] = p[start2++];
	}
	//检测剩余项，若有剩余，直接拷贝出来粘到合并序列尾
	while (start1<=end1)
		temp[k++] = p[start1++];
	while (start2<=end2)
		temp[k++] = p[start2++];
	//将排好序的数组拷贝到原数组
	for (i = 0; i < high - low + 1; ++i)
		p[low+i] = temp[i];

	free(temp);
}
