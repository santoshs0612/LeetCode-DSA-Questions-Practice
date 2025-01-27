class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        
        int n = arr.size();
        int left=0,right=1,count=0;
        while(left<n && right<n){

            if(arr[left]!=arr[right]){
                left++;
                arr[left] = arr[right];
                count++;
            }
            right++;
        }
        // cout<< count;
        return count+1;
        
    }
};