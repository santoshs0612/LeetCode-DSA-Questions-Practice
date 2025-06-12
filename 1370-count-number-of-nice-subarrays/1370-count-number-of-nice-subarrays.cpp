class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int r=0,sum=0,count=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        while(r<nums.size()){

            sum+= (nums[r]%2);

            if(mp.find(sum-k)!=mp.end()){
                count+=mp[sum-k];
            }
            mp[sum]++;
            r++;
        }
        return count;
        
    }
};