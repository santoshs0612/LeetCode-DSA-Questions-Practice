class Solution {
private:
    int solverRec(int ind,int n, vector<int> &cost){
        if(ind>=n){
            return 0;
        }

        int step1=0,step2 = 0;
        if(ind+1<=n-1){
            step1 = cost[ind+1]+ solverRec(ind+1,n,cost);
        }
        if(ind+2<=n-1){
            step2 = cost[ind+2]+solverRec(ind+2,n,cost);
        }

        return min(step1,step2);
    }
    int solverMem(int ind,int n, vector<int> &cost,vector<int> &dp){
        if(ind>=n){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int step1=0,step2 = 0;
        if(ind+1<=n-1){
            step1 = cost[ind+1]+ solverMem(ind+1,n,cost,dp);
        }
        if(ind+2<=n-1){
            step2 = cost[ind+2]+solverMem(ind+2,n,cost,dp);
        }

        return dp[ind]=min(step1,step2);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        // return min(solverRec(0,n,cost)+cost[0],cost[1]+solverRec(1,n,cost));

        vector<int> dp(n+1,-1);

        return min(solverMem(0,n,cost,dp)+cost[0],cost[1]+solverMem(1,n,cost,dp));
        
    }
};