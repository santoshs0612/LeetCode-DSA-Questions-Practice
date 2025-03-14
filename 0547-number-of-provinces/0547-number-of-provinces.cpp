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
        // int n = isConnected.size();
        // int m =isConnected[0].size();
        // vector<int> adj[n];
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(isConnected[i][j]==1){
        //             adj[i].push_back(j);
        //             adj[j].push_back(i);
        //         }
        //     }
        // }
        
        // int count=0;
        // vector<int> visited(n,0);
        // for(int i=0;i<n;i++){

        //     if(!visited[i]){
        //         count++;
        //         dfsSolverRec(i,adj,visited);
        //     }
        // }
        // return count;



///////// BFS Approach  
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
        int i=0;
        queue<int> q;
        while(i<n){
            for(i;i<n;i++){
                if(!visited[i]){
                    q.push(i);
                    count++;
                    visited[i]=1;
                    break;
                }
            }
            while(!q.empty()){

                int node = q.front();
                q.pop();

                for(auto nb:adj[node]){

                    if(!visited[nb]){
                        visited[nb]=1;
                        q.push(nb);
                    }
                }
            }
        }


        return count;


    }
};