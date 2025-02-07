class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();

        reverse(nums.begin(),nums.end());

        // reversefisrt k dights 
        if(k>n){
            k=k%n;
        }
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};