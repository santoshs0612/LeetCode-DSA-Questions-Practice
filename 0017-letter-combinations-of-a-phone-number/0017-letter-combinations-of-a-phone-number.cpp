class Solution {
private:
    void solverRec(string &digit, int ind ,unordered_map<char,string> &mp,vector<string>&ans,string temp){

        if(ind == digit.size()){
            ans.push_back(temp);
            return;
        }
        string curr = mp[digit[ind]];
        for(int i=0;i<curr.size();i++){
            temp+=curr[i];
            solverRec(digit,ind+1,mp,ans,temp);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0){
            return ans;
        }
        unordered_map<char,string> mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";

        solverRec(digits,0,mp,ans,"");
        return ans;
        
    }
};