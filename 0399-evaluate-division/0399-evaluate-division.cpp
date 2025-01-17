class Solution {
private:
    void dfsSolver(string &u, string &v,unordered_map<string, vector<pair<string,double>>> &adjList,unordered_set<string> &visited, double &ans, double temp){

        if(visited.find(u)!=visited.end()) return;

        visited.insert(u);

        if(u==v){
            ans = temp;
            return;
        }
        
        for(auto it : adjList[u]){

            string nbr = it.first;
            double val = it.second;
            dfsSolver(nbr,v,adjList,visited,ans,temp*val);
        }
        return;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
       // creating the adjList 
       unordered_map<string, vector<pair<string,double>>> adjList;  

        for(int i=0;i<equations.size();i++){

            string u = equations[i][0];
            string v = equations[i][1];

            adjList[u].push_back({v,values[i]});
            adjList[v].push_back({u,1/values[i]});
        }
        

        vector<double> result;

        for(int i=0;i< queries.size();i++){

            string u = queries[i][0];
            string v = queries[i][1];

            if(adjList.find(u)==adjList.end() || adjList.find(v)==adjList.end()){
                result.push_back(-1.0);
            }
            else{
                unordered_set<string> visited;
                double ans = -1.0, temp =1.0;
                dfsSolver(u,v,adjList,visited,ans,temp);
                result.push_back(ans);
            }
        }
        return result;
    }
};