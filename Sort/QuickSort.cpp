#include<iostream>

void QuickSort(int* nums,int size){
    if(size <= 1){
        return;
    }
    int flagIndex(0);   //�������±�
    //������С���ұߴ�
    for(int i(0);i < size; i++){
        if(nums[i] < nums[flagIndex]){
            int temp(nums[i]);
            for(int j(i); j > flagIndex; j--){
                nums[j] = nums[j-1];
            }
            nums[flagIndex] = temp;
            flagIndex++;
        }
    }
    QuickSort(nums,flagIndex++);
    QuickSort(nums+flagIndex,size-flagIndex);
}

