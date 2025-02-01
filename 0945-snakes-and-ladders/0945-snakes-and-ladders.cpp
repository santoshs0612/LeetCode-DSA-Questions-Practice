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

        vector<int> visited(n*n, INT_MAX);
        int res = INT_MAX;
        dfsSolverRec(0,0,res,board,visited);

        return (res == INT_MAX)? -1 :res;

    }
};