class Solution {
private:
        int solverRec(int n) {

        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(n==2){
            return 1;
        }
        if(n<0){
            return 0;
        }

        return solverRec(n-1)+solverRec(n-2)+solverRec(n-3);
        
    }
    int solverMem(int n, vector<int>&dp) {
        if(n<=0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return solverMem(n-1,dp)+solverMem(n-2,dp)+solverMem(n-3,dp);
    }
public:
    int tribonacci(int n) {
        vector<int>dp(38,0);

        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        // return solverMem(n,dp);
        if(n>=3){
            for(int i=3;i<=n;i++){
                dp[i]= dp[i-1]+dp[i-2]+dp[i-3];
            }
        }
        return dp[n];


    }
};