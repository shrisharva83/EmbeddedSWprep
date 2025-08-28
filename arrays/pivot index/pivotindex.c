int pivotIndex(int* nums, int numsSize) {
    int totalsum = 0;
    for (int i=0;i<numsSize;i++){
        totalsum += nums[i];
    }
    
    int leftsum = 0;
    int rightsum = 0;
    for(int i =0; i<numsSize; i++){
        rightsum = totalsum - nums[i] - leftsum;
        if(leftsum == rightsum){
            return i;
        }
        leftsum += nums[i];
    }
    return -1;
}
