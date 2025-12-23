class Solution {
public:

    int solverRec(int index, int prev, vector<int> &nums){

        //base case 

        if(index>= nums.size()){
            return 0;
        }

        // two cases take or not take

        // first not take 
        int notTake = solverRec(index+1, prev,nums);
        int take = 0;
        if(prev==-1 || nums[index] >nums[prev]){
            take =  solverRec(index+1, index, nums )+1;
        }
        return max(take, notTake);
    }
    int solverMemorization(int index, int prev, vector<int> &nums, vector<vector<int>> &dp){

        //base case 

        if(index>= nums.size()){
            return 0;
        }

        if(dp[index][prev+1]!=-1){
            return dp[index][prev+1];
        }

        // two cases take or not take

        // first not take 
        int notTake = solverMemorization(index+1, prev,nums,dp);
        int take = 0;
        if(prev==-1 || nums[index] >nums[prev]){
            take =  solverMemorization(index+1, index, nums,dp)+1;
        }
        return dp[index][prev+1]=max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {

        // recurssive apporach 
        // return solverRec(0,-1,nums);

        // Memorization 
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));

        return solverMemorization(0,-1,nums,dp);

    }
};