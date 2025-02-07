class Solution {

private:
    int solverRec(int buy, int ind, int cap , vector<int> &arr){

        if(ind> arr.size()-1){
            return 0;
        }

        if(buy==1){
            return max(solverRec(0,ind+1,cap,arr)-arr[ind], solverRec(1,ind+1,cap,arr));
        }
        if(buy==0){
            return max(solverRec(1,ind+1,cap-1,arr)+arr[ind],solverRec(0,ind+1,cap,arr));
        }
        return 0;

    }
    int solverMem(int buy, int ind, int cap , vector<int> &arr,vector<vector<int>> &dp){

        if(ind> arr.size()-1){
            return 0;
        }
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
        if(buy==1){
            return dp[ind][buy]=max(solverMem(0,ind+1,cap,arr,dp)-arr[ind], solverMem(1,ind+1,cap,arr,dp));
        }
        if(buy==0){
            return dp[ind][buy]=max(solverMem(1,ind+1,cap-1,arr,dp)+arr[ind],solverMem(0,ind+1,cap,arr,dp));
        }
        return dp[ind][buy]=0;

    }
public:
    int maxProfit(vector<int>& prices) {

        // int profit =0;
        // return solverRec(1,0,2,prices); 
        // vector<vector<int>> dp(prices.size()+1,vector<int>(3,-1));

        // return solverMem(1,0,2,prices,dp);
        vector<vector<int>> dp(prices.size()+1,vector<int>(3,0));

        int n = prices.size();
        for(int i=0;i<3;i++){
            dp[n][i]=0;
        }
        for(int ind =n-1;ind>=0;ind--){

            for(int buy =1;buy>=0;buy--){

                if(buy==1){
                    dp[ind][buy]=max(dp[ind+1][0]-prices[ind], dp[ind+1][1]);
                }
                else{
                    dp[ind][buy]=max(dp[ind+1][1]+prices[ind], dp[ind+1][0]);
                    
                }
            }
        }

        return dp[0][1];
    }
};