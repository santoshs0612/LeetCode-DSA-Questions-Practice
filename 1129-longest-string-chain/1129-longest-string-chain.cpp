class Solution {
private:
    bool isPosssible(string &a, string &b){

        int n = a.length();
        int m = b.length();

        if(m+1!=n){
            return false;
        }

        int i=0;
        int j=0;
        while(i<n){

            if(a[i]!=b[j]){
                i++;
            }else if(  j<m && a[i]==b[j]){
                i++;
                j++;
            }
        }
        if(i==n && j==m){
            return true;
        }
        else{
            return false;
        }

    }
public:
    int longestStrChain(vector<string>& words) {

        int maxLen =0;
        sort(words.begin(),words.end(),[](const string &a, const string &b){ return a.size()<b.size();});
        int n = words.size();
        vector<int> dp(n,1);

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){

                if(isPosssible(words[i],words[j]) && dp[i] < dp[j]+1){
                    dp[i] = 1+ dp[j];
                }
            }

            for(int i=0;i<n;i++){
                if(dp[i]>maxLen){
                    maxLen = dp[i];
                }
            }
            
        }
        return maxLen;
        
    }
};