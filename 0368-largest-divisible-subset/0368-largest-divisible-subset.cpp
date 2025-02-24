class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int maxLen=0;
        int n = nums.size();
        vector<int> dp(n,1);

        vector<int> hash(n);

        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j = 0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i] <dp[j]+1){
                    dp[i] = 1 +dp[j];
                    hash[i] = j;
                }
            }
        }
        vector<int> temp;
        int endInd =-1;

        for(int i=0;i<n;i++){

            if(dp[i]>maxLen){
                maxLen = dp[i];
                endInd = i;
            }
        }

        temp.push_back(nums[endInd]);

        while(hash[endInd]!=endInd){
            endInd = hash[endInd];
            temp.push_back(nums[endInd]);
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};