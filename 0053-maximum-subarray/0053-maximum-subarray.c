int maxSubArray(int* nums, int numsSize) {
    int currsum = 0, maxsum = INT_MIN, i;
    for(i=0; i<numsSize; i++){
        currsum += nums[i];
        maxsum = fmax(currsum, maxsum);
        if(currsum < 0){
            currsum = 0;
        } 
    }
    return maxsum;
}