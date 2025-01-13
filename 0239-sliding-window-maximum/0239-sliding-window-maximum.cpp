class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {



        vector<int> ans;
        deque<int> q;

        for(int i=0;i<nums.size();i++){

            // chack for the front element is out of bound 
            if(!q.empty() && q.front()==i-k){
                q.pop_front();
            }
            // check fro the last element is less the the current element 
            while(!q.empty() && nums[q.back()] < nums[i]){
                q.pop_back();
            }


            // push Current Index into the queue
            q.push_back(i);
            if(i>=k-1){
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};