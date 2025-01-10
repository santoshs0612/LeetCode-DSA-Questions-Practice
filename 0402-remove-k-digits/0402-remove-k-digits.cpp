class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        if(k>=n) return "0";
        
        stack<char> st;

        for(int i=0;i<n;i++){

            while(!st.empty() &&  st.top() > num[i] && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        // if k is still not zero 
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }

        // taking out the element from stack

        string ans = "";

        while(!st.empty()){
            ans+= st.top();
            st.pop();
        }
        if(ans==""){
            return "0";
        }
        
        // checking for zeros at back

        int m = ans.length();

        while(--m){

            if(ans.back()== '0'){
                ans.pop_back();
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;



    }
};