class Solution {
private:
    void solverRec(string &str, int opening, int closing, vector<string> &ans,int n){

        //base Case 
        if(opening==n && closing ==n){
            ans.push_back(str);
            return;
        }

        if(opening<n){

            str+='(';
            solverRec(str,opening+1,closing,ans,n);
            str.pop_back();
        }

        if(closing<opening){
            str+=')';
            solverRec(str,opening,closing+1,ans,n);
            str.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {


        vector<string> ans;
        int opening =0,closing =0;
        string str ="";
        solverRec(str,opening,closing,ans,n);

        return ans;
        
    }
};