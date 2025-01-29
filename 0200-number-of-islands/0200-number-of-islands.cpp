class Solution {
public:
    void dfsSolverRec(vector<vector<char>>& grid, vector<vector<int>>& visited,int x,int y){
        int X[] = {0,1,-1,0};
        int Y[] = {1,0,0,-1};
        int n = grid.size();
        int m = grid[0].size();
        visited[x][y] =1;

        for(int i=0;i<4;i++){

            int newx = x +X[i];
            int newy = y +Y[i];

            if(newx>=0 && newx<n && newy>=0 && newy<m && grid[newx][newy]=='1' && visited[newx][newy]!=1){
                dfsSolverRec(grid,visited,newx,newy);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int  m = grid[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));

        int count=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && visited[i][j]!=1){
                    count++;
                    dfsSolverRec(grid, visited,i,j);
                }
            }
        }
        return count;
    }
};