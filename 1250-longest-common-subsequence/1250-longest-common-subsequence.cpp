class Solution {
private:
    int solverRec(int n,int m,string &s1, string &s2){

        if(n<0 || m<0){
            return 0;
        }

        if(s1[n]==s2[m]){
            return 1+solverRec(n-1,m-1,s1,s2);
        }
        else{
            return max(solverRec(n-1,m,s1,s2), solverRec(n,m-1,s1,s2));
        }
    }
    int solverMem(int n,int m,string &s1, string &s2,vector<vector<int>> &dp){

        if(n<0 || m<0){
            return 0;
        }
        if(dp[n][m]!=-1){
           return dp[n][m];
        }
        if(s1[n]==s2[m]){
            return dp[n][m]=1+solverMem(n-1,m-1,s1,s2,dp);
        }
        else{
            return dp[n][m]=max(solverMem(n-1,m,s1,s2,dp), solverMem(n,m-1,s1,s2,dp));
        }
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        //return solverRec(n-1,m-1,text1,text2);

        // memorization 

        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        // return solverMem(n-1,m-1,text1,text2,dp);
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));


        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }

            }
        }

        return dp[n][m];
    }
};