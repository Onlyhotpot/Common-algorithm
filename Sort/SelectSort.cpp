#include<iostream>

void SelectSort(int* nums,int size){
    for(int i = 0; i < size-1; i++){
        int  min = nums[i], idx = i;
        for(int j = i; j < size; j++){
            if(min > nums[j]){
                min = nums[j];
                idx = j;
            }
        }
        nums[idx] = nums[i];
        nums[i] = min;
    }
}

