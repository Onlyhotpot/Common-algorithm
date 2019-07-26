
#include<iostream>

void BubbleSort(int* nums, int size){
    for(int i(0); i < size-1; i++){
        bool isSort(false);    //判断是否有交换
        for(int j(0); j < size-i-1; j++){
            if(nums[j] > nums[j+1]){
                isSort = true;
                //交换nums[j]与nums[j+1]的方法
                nums[j] ^= nums[j+1];
                nums[j+1] ^= nums[j];
                nums[j] ^= nums[j+1];
            }
        }
        if(!isSort){
            break;
        }
    }
}
