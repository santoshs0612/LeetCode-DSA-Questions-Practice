class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n = rooms.size();

        vector<int> visited(n,0);
        visited[0]=1;
        queue<int> q;
        q.push(0);
        while(!q.empty()){

            int node = q.front();
            q.pop();
            for(auto it:rooms[node]){
                if(!visited[it]){
                    visited[it]=1;
                    q.push(it);
                }
            }
        
        }

        for(int i=0;i<n;i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;        
    }
};