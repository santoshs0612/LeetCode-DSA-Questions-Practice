class Solution {
private:    
    int solverRec(int ind, int buy, vector<int>&price, int fee){
        if(ind >= price.size()){
            return 0;
        }
        int profit = 0;
        if(buy==1){
            profit  = max((-price[ind]+solverRec(ind+1,0,price, fee)), solverRec(ind+1,buy,price, fee));
        }if(buy==0){
            profit = max((price[ind]-fee+solverRec(ind+1,1,price,fee)), solverRec(ind+1,buy,price, fee));
        }

        return profit;
    }
    int solverMem(int ind, int buy, vector<int>&price, int fee,vector<vector<int>> &dp){
        if(ind >= price.size()){
            return 0;
        }
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
        int profit = 0;
        if(buy==1){
            profit  = max((-price[ind]+solverMem(ind+1,0,price, fee,dp)), solverMem(ind+1,buy,price, fee,dp));
        }if(buy==0){
            profit = max((price[ind]-fee+solverMem(ind+1,1,price,fee,dp)), solverMem(ind+1,buy,price, fee,dp));
        }

        return dp[ind][buy]=profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        

        // return solverRec(0,1,prices,fee);

        int n = prices.size();

        vector<vector<int>> dp(n+1, vector<int>(2,-1));

        return solverMem(0,1,prices,fee,dp);
        
    }
};