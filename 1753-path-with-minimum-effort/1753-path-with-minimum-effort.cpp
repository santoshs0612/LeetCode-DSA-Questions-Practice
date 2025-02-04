class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int minEffort = INT_MAX;

        int X[] = {0,1,-1,0};
        int Y[] = {1,0,0,-1};
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;

        q.push({0,{0,0}});

        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));

        dist[0][0] =0;

        while(!q.empty()){


            auto it = q.top();
            int diff = it.first;
            int x = it.second.first;
            int y = it.second.second;

            q.pop();
            if(x==n-1 && y ==m-1){
                return diff;
            }

            for(int i=0;i<4;i++){

                int newx = x + X[i];
                int newy = y + Y[i];

                if(newx >=0 && newy>=0 && newx<n && newy<m){
                    int newDiff = max(diff,abs(heights[newx][newy]-heights[x][y]));
                    if(newDiff<dist[newx][newy]){
                        dist[newx][newy] =newDiff;
                        q.push({newDiff,{newx,newy}});
                    }
                }
            }
        }

        return dist[n-1][m-1];
        
    }
};