
#include<iostream>

void BubbleSort(int* nums, int size){
    for(int i(0); i < size-1; i++){
        bool isSort(false);    //�ж��Ƿ��н���
        for(int j(0); j < size-i-1; j++){
            if(nums[j] > nums[j+1]){
                isSort = true;
                //����nums[j]��nums[j+1]�ķ���
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
