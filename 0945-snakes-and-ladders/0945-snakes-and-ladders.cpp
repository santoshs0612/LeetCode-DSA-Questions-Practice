class Solution {
private:
    pair<int,int> getCoordinates(int index, int n){
        int row = (n-1) -(index/n);
        int col = (index%n);
        if((n-row)%2 ==0){
            col = (n-1) -col;
        }
        return {row,col};
    }
    void dfsSolverRec(int pos, int move,int &res,vector<vector<int>> &board,vector<int> &visited){

        int n = board.size();
        if(pos == n*n-1){
            res = min(res,move);
            return;
        }

        if(visited[pos] <= move){
            return;
        }
        visited[pos] = move;

        for(int dice = 1;dice<=6;dice++){
            int newPos = pos + dice;
            if(newPos>= n*n) break;
            auto [newRow, newCol] = getCoordinates(newPos,n);

            if(board[newRow][newCol]!=-1){
                newPos = board[newRow][newCol]-1;
            }
            dfsSolverRec(newPos,move+1,res,board,visited);
        }
    }
    
public:
    int snakesAndLadders(vector<vector<int>>& board) {

        int n = board.size();

        // vector<int> visited(n*n, INT_MAX);
        int res = INT_MAX;
        // dfsSolverRec(0,0,res,board,visited);

        // return (res == INT_MAX)? -1 :res;

        vector<int> visited(n*n+1, -1);
        queue<pair<int,int>> q;
        q.push({1,0});
        visited[1] = 1;
        while(!q.empty()){
            
            int pos = q.front().first;
            int step = q.front().second;
            q.pop();
            if(pos == ((n*n))){
                return min(visited[n*n],step);
            }

            for(int i=1;i<=6;i++){
                int newPos = pos + i;
                if(newPos > n*n){
                    continue;
                }

                // boustrophedom grid conversion 
                int row = (newPos -1)/n;
                int col = (newPos-1)%n;
                if(row%2==1){
                    col = n-1-col;
                }
                row = n-1-row;

                if(board[row][col]!=-1){
                    newPos = board[row][col];
                }
                if(visited[newPos]==-1){
                    q.push({newPos,step+1});
                    visited[newPos]=step+1;
                }
                
            }

        }

        return -1;

    }
};