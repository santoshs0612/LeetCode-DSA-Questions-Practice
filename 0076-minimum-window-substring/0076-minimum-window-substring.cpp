class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();

        if(m>n) return "";
        //if(m==n) if(s!=t) return "";
        unordered_map<char,int> mp;
        for(auto it: t){
            mp[it]++;
        }

        int l =0,r=0,remChar=m;
        int maxLen = INT_MAX,start=n;
        while(r<n){
            if(mp.find(s[r])!=mp.end() && mp[s[r]]>0){
                remChar--;
            }
            mp[s[r]]--;
            if(remChar==0){
                while(remChar==0){
                    if(r-l+1<= maxLen){
                        maxLen = r-l+1;
                        start= l;
                    }
                    mp[s[l]]++;

                    if(mp[s[l]]>0) remChar++;
                    l++;
                }
            }
            r++;
        }
        return s.substr(start,maxLen);
    }
};