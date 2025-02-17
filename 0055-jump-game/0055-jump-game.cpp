class Solution {
public:
    bool canJump(vector<int>& nums) {
        int index=0;
        int n = nums.size();
        for(int i=0;i<n;i++){

            if(index <i){
                return false;
            }
            
            index = max(nums[i]+i,index);

            if(index>=n){
                return true;
            }
        }
        return true;
    }
};