class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {


        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int count=0;

        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }
        int X[]={0,-1,1,0};
        int Y[]={-1,0,0,1};
        int maxTime =0;
        while(!q.empty()){

            auto it = q.front();
            q.pop();
            int x = it.first.first;
            int y = it.first.second;
            int time =it.second;
            maxTime = max(time,maxTime);
            for(int i=0;i<4;i++){
                int newx = x+X[i];
                int newy = y+Y[i];
                if(newx>=0 && newx<n && newy>=0 
                    && newy<m && !visited[newx][newy] 
                        && grid[newx][newy]==1){
                            q.push({{newx,newy},time+1});
                            visited[newx][newy]=1;
                        }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]!=1 && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return maxTime;
    }
};