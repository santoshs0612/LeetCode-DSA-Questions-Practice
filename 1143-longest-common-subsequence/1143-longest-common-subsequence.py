class Solution:
    def solverRec(self,i, j, n,m,text1,text2):

        if i>=n or j>=m:
            return 0
        
        if text1[i]==text2[j]:
            return 1+self.solverRec(i+1,j+1,n,m,text1,text2)
        else:
            return max(self.solverRec(i+1,j,n,m,text1, text2), self.solverRec(i,j+1,n,m,text1,text2))
    def solverMem(self,i, j, n,m,text1,text2,dp):

        if i>=n or j>=m:
            return 0
        if dp[i][j]!=-1:
            return dp[i][j]
        if text1[i]==text2[j]:
            dp[i][j]=1+self.solverMem(i+1,j+1,n,m,text1,text2,dp)
        else:
            dp[i][j]=max(self.solverMem(i+1,j,n,m,text1, text2,dp), self.solverMem(i,j+1,n,m,text1,text2,dp))
        return dp[i][j]
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:

        n = len(text1)
        m = len(text2)

        # return self.solverRec(0,0,n,m, text1, text2)
        
        dp = [[-1]*m for _ in range(n)]

        return self.solverMem(0,0,n,m, text1, text2,dp)