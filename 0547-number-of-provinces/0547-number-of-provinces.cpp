class Solution {
private:    
    void dfsSolverRec(int node, vector<int> adj[], vector<int> &visited){

        visited[node]=1;

        for(auto it:adj[node]){

            if(!visited[it]){
                dfsSolverRec(it,adj,visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m =isConnected[0].size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int count=0;
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){

            if(!visited[i]){
                count++;
                dfsSolverRec(i,adj,visited);
            }
        }
        return count;
    }
};