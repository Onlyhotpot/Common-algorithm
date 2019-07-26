#include<iostream>

void InsertSort(int* nums,int size){
    for(int i(1); i < size; i++){
        int j(i);
        int temp(nums[i]);
        while(j > 0 && temp < nums[j-1]){
            nums[j] = nums[--j];
        }
        nums[j] = temp;
    }
}

