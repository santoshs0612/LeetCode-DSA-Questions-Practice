class Solution {
private:
    int solverRec(int ind, int prev , vector<int> &arr){

        if(ind==arr.size()){
            return 0;
        }

        int notTake = solverRec(ind+1,prev,arr);
        int take = 0;
        
        if(prev ==-1 || arr[ind]>arr[prev]){
            take = solverRec(ind+1,ind,arr)+1;
        }
        return max(notTake, take);
    }
    int solverMem(int ind, int prev , vector<int> &arr,vector<vector<int>> &dp){

        if(ind==arr.size()){
            return 0;
        }

        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }

        int notTake = solverMem(ind+1,prev,arr,dp);
        int take = 0;
        
        if(prev ==-1 || arr[ind]>arr[prev]){
            take = solverMem(ind+1,ind,arr,dp)+1;
        }
        return dp[ind][prev+1]=max(notTake, take);
    }
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        // return solverRec(0,-1,nums);

        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        // return solverMem(0,-1,nums, dp);

        // vector<vector<int>> dp(n+1,vector<int>(n+1,0));


        // for(int ind=n-1;ind>=0;ind--){

        //     for(int prev = ind-1;prev>=-1;prev--){

        //         int notTake = dp[ind+1][prev+1];
        //         int take = 0;
                
        //         if(prev ==-1 || nums[ind]>nums[prev]){
        //             take = dp[ind+1][ind+1]+1;
        //         }
        //         dp[ind][prev+1]=max(notTake, take);
        //     }
        // }
        // return dp[0][0];


        vector<int> dp(n,1);

        for(int ind=0;ind<n;ind++){
            for(int prevInd =0;prevInd<=ind-1;prevInd++){

                if(nums[prevInd]<nums[ind]){
                    dp[ind] = max(dp[ind], 1+dp[prevInd]);
                }
            }
        }

        int maxLen = 0;

        for(int i=0;i<n;i++){

            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
        
    }
};