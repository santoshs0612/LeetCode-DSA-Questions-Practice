class Solution {
public:

    void solverRec(int open, int close, string temp, vector<string> &ans){

        if(open ==0 && close==0){
            ans.push_back(temp);
            return;
        }

        if(open> 0){
            solverRec(open-1,close,temp+'(',ans);
        }

        if(close>open){
            solverRec(open,close-1,temp+')',ans);
        }
        
    }
    vector<string> generateParenthesis(int n) {


        vector<string> ans;
        string temp ="";
        solverRec(n,n,temp,ans);

        return ans;
        
        
    }
};