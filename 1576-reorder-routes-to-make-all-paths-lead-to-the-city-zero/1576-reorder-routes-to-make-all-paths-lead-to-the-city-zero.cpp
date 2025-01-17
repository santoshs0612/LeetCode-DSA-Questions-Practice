class Solution {
private:
    void dfsSolver(int node, vector<vector<pair<int,int>>> &adjList,vector<int> &visited){

        visited[node]=1;
        for(auto it:adjList[node]){
            int nbNode = it.first;
            int val=it.second;
            if(visited[nbNode]==0){
                count+=val;
                dfsSolver(nbNode,adjList,visited);
            }
              
        }
    }
public:
    int count =0 ; 
    int minReorder(int n, vector<vector<int>>& connections) {
        // int count=0;
        // int m = connections.size();
        // vector<int> visited(n,0);
        // // creating a adj List 
        // vector<vector<int>> adjList(n);
        // vector<vector<int>> revAdjList(n);
        // for(auto connection:connections){
        //     adjList[connection[0]].push_back(connection[1]);
        //     revAdjList[connection[1]].push_back(connection[0]);
        // }

        // queue<int> q;
        // q.push(0);
        // visited[0]=1;

        // while(!q.empty()){

        //     int node = q.front();
        //     q.pop();

        //     for(auto nb:adjList[node]){
        //         if(!visited[nb]){
        //             count++;
        //             q.push(nb);
        //             visited[nb]=1;
        //         }
        //     }
        //     for(auto nb:revAdjList[node]){
        //         if(!visited[nb]){
        //             q.push(nb);
        //             visited[nb]=1;
        //         }
        //     }
        // }
        // return count;


        // dfs 

        vector<int> visited(n,0);
        vector<vector<pair<int,int>>> adjList(n);

        for(auto &connection: connections){
            adjList[connection[0]].push_back({connection[1],1});
            adjList[connection[1]].push_back({connection[0],0});
        }
        dfsSolver(0,adjList,visited);
        return count;
        
    }
};