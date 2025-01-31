class Solution {
public:
    void solve(vector<vector<char>>& board) {

        int n  = board.size();
        int m = board[0].size();

        // visited array 
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(i==0 || j==0){
                    if(board[i][j]=='O'){
                        q.push({i,j});
                        visited[i][j]=1;
                    }
                }
                if(i==n-1 || j==m-1){
                    if(board[i][j]=='O'){
                        q.push({i,j});
                        visited[i][j]=1;
                    }
                }
            }
        }

        int  X[]= {0,1,-1,0};
        int Y[]= {1,0,0,-1};
        while(!q.empty()){

            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int newx = x +X[i];
                int newy = y +Y[i];

                if(newx >=0 && newx<n && newy >=0 && newy<m && visited[newx][newy]==0 && board[newx][newy]=='O'){
                    q.push({newx,newy});
                    visited[newx][newy]=1;
                }
            }
            
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(visited[i][j]==0 && board[i][j]=='O'){
                    board[i][j] ='X';
                }
            }
        }
        
    }
};