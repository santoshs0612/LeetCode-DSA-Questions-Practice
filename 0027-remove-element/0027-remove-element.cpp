class Solution {
public:
    int removeElement(vector<int>& arr, int val) {
        int count =0;

        int left =0,right=0;
        int n = arr.size();
        while(right<n){

            if(arr[right]!=val){
                arr[left++]=arr[right];
                count++;
                
            }
            right++;
        }

        return count;
        
    }
};