class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        

        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        int res = INT_MAX;
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]!=0 || grid[n-1][m-1]!=0){
            return -1;
        }
        if(n==1 && m==1 && grid[0][0]==0){
            return 1;
        }
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0] =1;
        int X[]={-1,1,0,0,-1,1,-1,1};
        int Y[]={0,0,1,-1,1,1,-1,-1};

        while(!q.empty()){

            auto it = q.front();
            int d = it.first;
            int x = it.second.first;
            int y = it.second.second;
            q.pop();
            for(int i=0;i<8;i++){

                int newx = x + X[i];
                int newy = y + Y[i];

                if(newx>=0 && newy>=0 &&newx<n && newy<m && grid[newx][newy]==0){

                    if((d+1) < dist[newx][newy]){
                        dist[newx][newy] = d+ 1;
                        q.push({dist[newx][newy] ,{newx,newy}});
                    }
                    if(newx ==n-1 && newy ==m-1){
                        res = min(res,dist[newx][newy]);
                    }
                }
            }
        }

        if(res==INT_MAX){
            return -1;
        }

        return res;
        
    }
};