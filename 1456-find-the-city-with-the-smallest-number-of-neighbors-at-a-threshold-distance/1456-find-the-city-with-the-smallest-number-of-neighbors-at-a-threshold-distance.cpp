class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> grid(n,vector<int>(n,1e9));

        for(auto it:edges){
            grid[it[0]][it[1]]= it[2];
            grid[it[1]][it[0]]= it[2];
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){

                    grid[i][j] = min(grid[i][j], 
                                    grid[i][k] +grid[k][j]);
                }
            }
        }

        for(int i=0;i<n;i++){
            grid[i][i]=0;
        }
        int city =INT_MAX;
        int minCity =0;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(grid[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count<=city){
                minCity = i;
                city = count;
            }
        }
        return minCity;
    }
};