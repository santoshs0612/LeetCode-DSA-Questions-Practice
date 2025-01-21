class Solution {
private:
    int solverRec(vector<int> &nums, int ind){

        if(ind<0){
            return 0;
        }

        // take tha house 

        int take =  nums[ind] + solverRec(nums,ind-2);

        int notTake = 0 + solverRec(nums,ind-1);
        
        return max(take, notTake);
    }
    int solverMem(vector<int> &nums, int ind, vector<int> &dp){

        if(ind<0){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }

        // take tha house 

        int take =  nums[ind] + solverMem(nums,ind-2,dp);

        int notTake = 0 + solverMem(nums,ind-1,dp);
        
        return dp[ind] = max(take, notTake);
    }
    
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // return solverRec(nums,n-1);

        // memorizations 

        vector<int> dp(n+1,-1);

        return solverMem(nums,n-1,dp);
    }
};