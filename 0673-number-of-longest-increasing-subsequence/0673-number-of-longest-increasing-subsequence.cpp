class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n,1);
        vector<int> count(n,1);

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){

                if(nums[j]< nums[i] && dp[i] <1+dp[j]){
                    dp[i] = 1+dp[j];
                    count[i] = count[j];
                }else if(nums[j]< nums[i] && dp[i] ==1+dp[j]){
                    count[i] = count[j] + count[i];
                }
            }
        }

        int maxLen = 1;
        for(int i=0;i<n;i++){
            if(dp[i]>maxLen){
                maxLen = dp[i];
            }
        }
        int ct=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxLen){
                ct+= count[i];
            }
        }
        return ct;
        
    }
};