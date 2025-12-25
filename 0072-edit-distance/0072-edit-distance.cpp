class Solution {
public:
    int solverRec(int i, int j, string word1, string word2){

        // base case  
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }

        if(word1[i]==word2[j]){
            return solverRec(i-1,j-1,word1,word2);
        }else{
            int deleteChar = solverRec(i-1,j,word1,word2);
            int insert = solverRec(i,j-1,word1,word2);
            int replace = solverRec(i-1,j-1,word1,word2);

            return 1+ min(deleteChar, min(insert,replace));
        }
    }
    int solverMem(int i, int j, string word1, string word2, vector<vector<int>>&dp){

        // base case  
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(word1[i]==word2[j]){
            return dp[i][j]=solverMem(i-1,j-1,word1,word2,dp);
        }else{
            int deleteChar = solverMem(i-1,j,word1,word2,dp);
            int insert = solverMem(i,j-1,word1,word2,dp);
            int replace = solverMem(i-1,j-1,word1,word2,dp);

            return dp[i][j]=1+ min(deleteChar, min(insert,replace));
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        // return solverRec(n-1,m-1,word1,word2);
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return solverMem(n-1,m-1,word1,word2,dp);
        
    }
};