class Solution {
private:
    int solver(vector<int> arr){

        int n = arr.size();
        vector<int> leftMin(n,0);
        vector<int> rightMin(n,0);
        // finding out the left min aarray
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                leftMin[i]=0;
            }else{
                leftMin[i]= st.top()+1;
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // right min array
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>= arr[i]){
                st.pop();
            }
            if(st.empty()){
                rightMin[i]=n-1;
            }else{
                rightMin[i]=st.top()-1;
            }
            st.push(i);
        }

        //maxArea 
        int maxArea=0;
        for(int i=0;i<n;i++){
            maxArea = max(arr[i]*(rightMin[i]-leftMin[i]+1),maxArea);
        }
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n =matrix.size();
        int m = matrix[0].size();
        int maxArea =0;
        vector<int> temp(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0'){
                    temp[j]=0;
                }else{
                    temp[j]+=1;
                }
            }
            maxArea =max(solver(temp),maxArea);

        }
        return maxArea;

    }
};