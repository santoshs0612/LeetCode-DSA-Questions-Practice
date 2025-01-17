class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int count=0;
        int m = connections.size();
        vector<int> visited(n,0);
        // creating a adj List 
        vector<vector<int>> adjList(n);
        vector<vector<int>> revAdjList(n);
        for(auto connection:connections){
            adjList[connection[0]].push_back(connection[1]);
            revAdjList[connection[1]].push_back(connection[0]);
        }

        queue<int> q;
        q.push(0);
        visited[0]=1;

        while(!q.empty()){

            int node = q.front();
            q.pop();

            for(auto nb:adjList[node]){
                if(!visited[nb]){
                    count++;
                    q.push(nb);
                    visited[nb]=1;
                }
            }
            for(auto nb:revAdjList[node]){
                if(!visited[nb]){
                    q.push(nb);
                    visited[nb]=1;
                }
            }
        }
        return count;
        
    }
};