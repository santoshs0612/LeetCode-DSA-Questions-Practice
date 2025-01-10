class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& arr1, vector<int>& arr2) {
        
        int n = arr1.size();
        int m = arr2.size();
        vector<int> ans(n,0);

        vector<int> nge(m,-1);
        stack<int> st;

        for(int i=m-1;i>=0;i--){

            while(!st.empty() && st.top()<= arr2[i]){
                st.pop();
            }

            if(st.empty()){
                nge[i]=-1;
            }
            else{
                nge[i]= st.top();
            }
            st.push(arr2[i]);
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr1[i]==arr2[j]){
                    ans[i]=nge[j];
                }
            }
        }


        return ans;

    }
};