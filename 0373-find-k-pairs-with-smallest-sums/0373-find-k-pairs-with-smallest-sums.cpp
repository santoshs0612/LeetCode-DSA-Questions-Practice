class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>> pq;
        int n = nums1.size();
        // adding the second array all with first element of array 1
        for(int j=0;j<nums2.size();j++){
            pq.push({nums1[0]+nums2[j],{0,j}});
        }



        vector<vector<int>> ans;

        while(k-- && !pq.empty()){
            auto it = pq.top();
            int i = it.second.first;
            int j = it.second.second;
            pq.pop();
            ans.push_back({nums1[i],nums2[j]});
            if(i+1<nums1.size()){
                pq.push({nums1[i+1]+nums2[j],{i+1,j}});
            }
            
        }
        return ans;
    }
};