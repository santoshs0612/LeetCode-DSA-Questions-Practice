class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));

        queue<pair<int,int>>q;
        int totalOrange=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }if(grid[i][j]!=0){
                    totalOrange++;
                }
            }
        }
        int X[]={0,1,-1,0};
        int Y[]={1,0,0,-1};
        int time=0;
        int totalOperations=0;
        while(!q.empty()){

            int qSize = q.size();
            if(qSize){
                time++;
            }

            totalOperations+=qSize;
            for(int i=0;i<qSize;i++){

                auto it = q.front();
                int x = it.first;
                int y = it.second;
                q.pop();
                for(int i=0;i<4;i++){

                    int newx= x+X[i];
                    int newy= y+Y[i];

                    if(newx >=0 && newx<n && newy >=0 && newy<m && visited[newx][newy]==0 && 
                        grid[newx][newy]==1){
                            visited[newx][newy]=1;
                            q.push({newx,newy});
                        }
                }

            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && grid[i][j]==1){
                    return -1;
                }
            }
        }


        if(totalOperations==totalOrange){
            if(time==0){
                return time;
            }
            return time-1;
        }else{
            return -1;
        }
        


        
    }
};