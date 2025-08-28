class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalsum=0;
        for(int num:nums){
            totalsum += num;
        }

        int leftsum = 0;
        int rightsum = 0;

        for(int i=0; i< nums.size(); i++){
            rightsum = totalsum - nums[i] - leftsum;
            if(rightsum == leftsum){
                return i;
            }
            leftsum+= nums[i];

        }
        return -1;
        
    }
};
