class Solution {
private:
    int solverRec(int i,int j, vector<int> &nums){

        if(i>j){
            return 0;
        }

        int minBallon = INT_MIN;

        for(int k=i;k<=j;k++){

            int val = nums[i-1]*nums[k]*nums[j+1];
            int rem = solverRec(i,k-1,nums)+ solverRec(k+1,j,nums);
            minBallon = max(minBallon,val+rem);
        }
        return minBallon;
    }
    int solverMem(int i,int j, vector<int> &nums,vector<vector<int>> &dp){

        if(i>j){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int minBallon = INT_MIN;

        for(int k=i;k<=j;k++){

            int val = nums[i-1]*nums[k]*nums[j+1];
            int rem = solverMem(i,k-1,nums,dp)+ solverMem(k+1,j,nums,dp);
            minBallon = max(minBallon,val+rem);
        }
        return dp[i][j]=minBallon;
    }
public:
    int maxCoins(vector<int>& nums) {
        
        // int n = nums.size();
        // nums.push_back(1);
        // nums.insert(nums.begin(),1);

        // return solverRec(1,n,nums);
        // int n = nums.size();
        // nums.push_back(1);
        // nums.insert(nums.begin(),1);

        // vector<vector<int>> dp(n+2,vector<int>(n+2,-1));

        // return solverMem(1,n,nums,dp);
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);

        vector<vector<int>> dp(n+2,vector<int>(n+2,0));

        for(int i= n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i>j){
                    continue;
                }

                int minBallon = INT_MIN;

                for(int k=i;k<=j;k++){
                    int val = nums[i-1]*nums[k]*nums[j+1]+ dp[i][k-1]+ dp[k+1][j];
                    minBallon = max(minBallon,val);
                }
                dp[i][j]=minBallon;

            }
        }

        return dp[1][n];
    }
};