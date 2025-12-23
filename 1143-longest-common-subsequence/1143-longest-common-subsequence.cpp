class Solution {
public:
    int solverRec(int i, int j, int n, int m, string &str1, string &str2){

        //base case 

        if(i>=n || j>=m){
            return 0;
        }

        // comparing the the string

        if(str1[i]==str2[j]){
            return 1+solverRec(i+1,j+1,n,m,str1,str2);
        }
        else{
            return max(solverRec(i+1,j,n,m,str1,str2), solverRec(i,j+1,n,m,str1,str2));
        }
    }

    int solverMem(int i, int j, int n, int m, string &str1, string &str2, vector<vector<int>> &dp){

        //base case 

        if(i>=n || j>=m){
            return 0;
        }
        // check the dp state 

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        // comparing the the string

        if(str1[i]==str2[j]){
            return dp[i][j]=1+solverMem(i+1,j+1,n,m,str1,str2,dp);
        }
        else{
            return dp[i][j]=max(solverMem(i+1,j,n,m,str1,str2,dp), solverMem(i,j+1,n,m,str1,str2,dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.size();
        int m = text2.size();

        // return solverRec(0,0, n,m,text1, text2);

        vector<vector<int>> dp(n+1, vector<int> (m+1,-1));

        return solverMem(0,0,n,m,text1,text2,dp);
        
    }
};