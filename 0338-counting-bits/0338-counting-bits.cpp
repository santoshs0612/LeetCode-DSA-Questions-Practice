class Solution {
private:    
    int solver(int n){

        int count=0;

        while(n){

            if(n&1){
                count++;
            }
            n>>=1;
        }
        return count;
    }
public:
    vector<int> countBits(int n) {

        vector<int> ans ;
        
        for(int i=0;i<=n;i++){
            ans.push_back(solver(i));
        }
        return ans;
        
    }
};