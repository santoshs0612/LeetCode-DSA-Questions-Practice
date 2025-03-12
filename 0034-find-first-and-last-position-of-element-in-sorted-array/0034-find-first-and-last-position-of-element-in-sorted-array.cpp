class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int n = nums.size();
        int low = 0, high = n-1;
        int firstIndex = -1, lastIndex = -1;

        // checking the first Index 

        while(low <= high){

            int mid = low + (high -low)/2;

            if(nums[mid] == target){
                firstIndex = mid ;
                high = mid-1;
            }else if(nums[mid]< target){
                low = mid +1;
            }else{
                high = mid-1;
            }
        }

        // checking the last Index 
        low = 0, high = n-1;
        while(low <= high){

            int mid = low + (high -low)/2;

            if(nums[mid] == target){
                lastIndex = mid ;
                low = mid+1;
            }else if(nums[mid]< target){
                low = mid +1;
            }else{
                high = mid-1;
            }
        }
        return {firstIndex, lastIndex};
        
    }
};