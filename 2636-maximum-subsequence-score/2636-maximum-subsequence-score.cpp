class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

        long long ans = 0;
        int n = nums1.size();
        vector<pair<int,int>>combined;
        for(int i=0;i<n;i++){
            combined.push_back({nums2[i],nums1[i]});
        }

        sort(combined.rbegin(),combined.rend());
        long long sum =0;
        priority_queue<int,vector<int>, greater<int>> pq;
        for(auto it:combined){
            int val2 = it.first;
            int val1= it.second;

            sum+=val1;
            pq.push(val1);
            

            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size()==k){
                ans = max(ans, sum*val2);
            }

        }

        return ans;

        
    }
};