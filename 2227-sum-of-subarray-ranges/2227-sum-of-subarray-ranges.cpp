class Solution {

vector<long long> pseIndex(vector<int> &arr){
    int n = arr.size();
    vector<long long> ans(n);
    stack<long long> st;
    for(int i=0;i<n;i++){

        while(!st.empty() && arr[st.top()]>= arr[i]){
            st.pop();
        }

        if(st.empty()){
            ans[i]=-1;
        }else{
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}


vector<long long> nseIndex(vector<int> &arr){
    int n = arr.size();
    vector<long long> ans(n);
    stack<long long> st;
    for(int i=n-1;i>=0;i--){

        while(!st.empty() && arr[st.top()]> arr[i]){
            st.pop();
        }

        if(st.empty()){
            ans[i]=n;
        }else{
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}

vector<long long> pgeIndex(vector<int> &arr){
    int n = arr.size();
    vector<long long> ans(n);
    stack<long long> st;
    for(int i=0;i<n;i++){

        while(!st.empty() && arr[st.top()]<= arr[i]){
            st.pop();
        }

        if(st.empty()){
            ans[i]=-1;
        }else{
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}


vector<long long> ngeIndex(vector<int> &arr){
    int n = arr.size();
    vector<long long> ans(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){

        while(!st.empty() && arr[st.top()]< arr[i]){
            st.pop();
        }

        if(st.empty()){
            ans[i]=n;
        }else{
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}

long long minSum(vector<int> &arr){

    int n = arr.size();

    vector<long long> pse= pseIndex(arr);
    vector<long long> nse =nseIndex(arr);
    long long sum=0;
    for(int i=0;i<n;i++){

        long long leftcount = i-pse[i];
        long long rightcount = nse[i]-i;
        sum = sum+(leftcount*rightcount*arr[i]);
    }
    return sum;
}


long long maxSum(vector<int> &arr){

    int n = arr.size();

    vector<long long> pge= pgeIndex(arr);
    vector<long long> nge =ngeIndex(arr);
    long long sum=0;
    for(int i=0;i<n;i++){

        long long leftcount = i-pge[i];
        long long rightcount = nge[i]-i;
        sum = sum+(leftcount*rightcount*arr[i]);
    }
    return sum;
}
public:
    long long subArrayRanges(vector<int>& arr) {



        // long long diff = 0;
        // int n=arr.size();
        // for(int i=0;i<n;i++){
        //     int maxVal=arr[i];
        //     int smallest=arr[i];
        //     for(int j=i;j<n;j++){
        //         maxVal= max(maxVal,arr[j]);
        //         smallest = min(smallest,arr[j]);
        //         diff+=(maxVal-smallest);
        //     }
        // }
        // return diff;

        // optimized way

        // finding minimum element form sub arr

        long long minsum = minSum(arr);
        long long maxsum = maxSum(arr);

        return maxsum-minsum;
        
    }
};