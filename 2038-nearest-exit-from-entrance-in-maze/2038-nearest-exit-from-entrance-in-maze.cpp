class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        int step =0;

        int n = maze.size();
        int m = maze[0].size();
        int e1 = entrance[0],e2 = entrance[1];
        vector<vector<int>> visited(n,vector<int>(m,0));
        visited[e1][e2]=1;

        queue<pair<int,pair<int,int>>> q;
        q.push({0,{e1,e2}});
        int X[]={0,0,-1,1};
        int Y[]={1,-1,0,0};
        while(!q.empty()){
            
            auto it = q.front();
            q.pop();
            int dist  = it.first;
            int x  = it.second.first;
            int y = it.second.second;
            // if((x==0 || x == n-1) || (y == 0 || y == m-1)){
            //     return dist;
            // }
            for(int i=0;i<4;i++){

                int newx = x + X[i];
                int newy = y + Y[i];

                if(newx>=0 && newx<n && newy>=0 && newy<m && visited[newx][newy]==0 && maze[newx][newy]== '.'){

                    if((newx==0 || newx == n-1) || (newy == 0 || newy == m-1)){
                        return dist+1;
                    }
                    visited[newx][newy]=1;
                    q.push({dist+1,{newx,newy}});
                }
            }

        }

        return -1;
        
    }
};