class Solution {
private:
    bool dfSolverRec(int node,vector<vector<int>> &adj,vector<int> &visited,vector<int> &pathVisited){

        visited[node]=1;
        pathVisited[node]=1;
        for(auto it: adj[node]){
            if(!visited[it]){
                if(dfSolverRec(it,adj,visited,pathVisited)==true){
                    return true;
                }
            }else if(pathVisited[it]==1){
                return true;
            }
        }
        pathVisited[node]=0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {



        vector<vector<int>> adj(numCourses);

        for(auto &it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> visited(numCourses,0);
        vector<int> pathVisited(numCourses,0);

        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfSolverRec(i,adj,visited,pathVisited)==true){
                    return false;
                }
            }
        }
        return true;


        
    }
};