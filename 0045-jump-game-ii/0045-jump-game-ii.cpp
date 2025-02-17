class Solution {
public:
    int jump(vector<int>& nums) {

        int index=0;
        int jump =0,step =0;
        int n = nums.size();
        if(n==1 || nums[0]==0){
            return 0;
        }
        for(int i=0;i<n;i++){

            step = max(i+nums[i],step);
            if(index==i){
                //increase the jump count
                index = step;
                jump++;
                if(index>=n-1){
                    return jump;
                }
            }
            if(index<i){
                return 0;
            }
        }
        return jump;
        
    }
};