class Solution {
int solverRec(int x, int y){
    if(x==0 && y==0){
        return 1;
    }
    if(x<0 || y<0){
        return 0;
    }

    return solverRec(x,y-1) + solverRec(x-1,y);
}
int solverMem(int x, int y, vector<vector<int>> &dp){
    if(x==0 && y==0){
        return 1;
    }
    if(x<0 || y<0){
        return 0;
    }
    if(dp[x][y]!=-1){
        return dp[x][y];
    }

    return dp[x][y]=solverMem(x,y-1,dp) + solverMem(x-1,y,dp);
}
public:
    int uniquePaths(int m, int n) {


        // return solverRec(m-1,n-1);

        //memorization 

        // vector<vector<int>> dp(m+1, vector<int>(n+1,-1));

        // return solverMem(m-1,n-1,dp);


        // top down 

        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(int i=0;i<m;i++){
            dp[i][0]=1;
        }
        for(int i=0;i<n;i++){
            dp[0][i]=1;
        }

        for(int x = 1;x<m;x++){
            for(int y = 1;y<n;y++){
                
                
                dp[x][y]=dp[x][y-1] + dp[x-1][y];
                
                

            }
        }

        return dp[m-1][n-1];
        
    }
};