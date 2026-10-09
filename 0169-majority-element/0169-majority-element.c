int majorityElement(int* nums, int numsSize) {
    int freq=0,ans=0, i;
    for(i=0;i<numsSize;i++){
        if(freq==0){
            ans=nums[i];
        }
        if(ans==nums[i]){
            freq++;
        }else{
            freq--;
        }
    }
    return ans;
}