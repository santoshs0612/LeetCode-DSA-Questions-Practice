class Solution {
private:
    // finding out the previous smaalest element 
    vector<int> pse(vector<int> &arr){
        int n =arr.size();
        vector<int> ans(n,0);
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }

            if(st.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    // finding out the next smalest element 
    vector<int> nse(vector<int> &arr){
        int n =arr.size();
        vector<int> ans(n,0);
        stack<int> st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            if(st.empty()){
                ans[i] = n-1;
            }
            else{
                ans[i] = st.top()-1;
            }
            st.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& arr) {
        
        // int largestArea = 0;
        // int n = arr.size();
        // for(int i =0;i<n;i++){

        //     int minVal = arr[i];
        //     for(int j=i;j<n;j++){

        //         minVal = min(minVal,arr[j]);

        //         largestArea = max(largestArea, minVal*(j-i+1));
        //     }
        // }
        // return largestArea;
        int n = arr.size();
        vector<int> previousSmallest = pse(arr);
        vector<int> nextSmallest = nse(arr);
        int largestHisto=0;
        for(int i=0;i<n;i++){
            largestHisto =  max(largestHisto,(nextSmallest[i]-previousSmallest[i])*arr[i]);
        }
        return largestHisto;
    }
};