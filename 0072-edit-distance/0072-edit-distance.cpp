class Solution {
private:
    int solverRec(int n, int m , string str1, string str2){

        // base case 
        if(n<0){
            return m+1;
        }
        if(m<0){
            return n+1;
        }

        if(str1[n]==str2[m]){
            return solverRec(n-1,m-1,str1,str2);
        }
        // if(str1[n]!=str2[n]){
            return 1+min(solverRec(n,m-1,str1,str2),min(solverRec(n-1,m,str1,str2),solverRec(n-1,m-1,str1,str2)));
        
    }
    int solverMem(int n, int m , string str1, string str2,vector<vector<int>> &dp){

        // base case 
        if(n<0){
            return m+1;
        }
        if(m<0){
            return n+1;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(str1[n]==str2[m]){
            return dp[n][m]=solverMem(n-1,m-1,str1,str2,dp);
        }
        // if(str1[n]!=str2[n]){
            return dp[n][m]=1+min(solverMem(n,m-1,str1,str2,dp),min(solverMem(n-1,m,str1,str2,dp),solverMem(n-1,m-1,str1,str2,dp)));
        
    }
public:
    int minDistance(string word1, string word2) {

        int n= word1.length();
        int m = word2.length();

        // return solverRec(n-1,m-1,word1,word2);

        // memorization  
        // vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        // return solverMem(n-1,m-1,word1,word2,dp);
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int i=0;i<=m;i++){
            dp[0][i]=i;
        }
        for(int ind1= 1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(word1[ind1-1]==word2[ind2-1]){
                    dp[ind1][ind2]=dp[ind1-1][ind2-1];
                }
                // if(str1[n]!=str2[n]){
                else{
                    dp[ind1][ind2]=1+min(dp[ind1][ind2-1],min(dp[ind1-1][ind2],dp[ind1-1][ind2-1]));
                }
                
            }
        }
        return dp[n][m];
    }
};