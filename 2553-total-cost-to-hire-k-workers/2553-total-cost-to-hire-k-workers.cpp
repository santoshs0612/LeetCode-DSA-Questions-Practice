class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {

        priority_queue<int,vector<int>,greater<int>> pq1;
        priority_queue<int,vector<int>,greater<int>> pq2;
        long long ans =0;
        // entering the elemenet into pq1
        int n = costs.size();
        int i=0,j=n-1;
        for(i=0;i<candidates;i++){
            pq1.push(costs[i]);
        }

        while(candidates >= (n-j )&& j>=i){
            pq2.push(costs[j--]);
        }
        int c1,c2;
        while(k--){


            if(pq1.empty()){
                c1 = INT_MAX;
            }else{
                c1 = pq1.top();
            }

            if(pq2.empty()){
                c2 = INT_MAX;
            }else{
                c2 = pq2.top();
            }

            if(c1 <=c2){
                ans+=c1;
                pq1.pop();
                if(i<=j){
                    pq1.push(costs[i++]);
                }
            }else if(c1>c2){
                ans+=c2;
                pq2.pop();
                if(j>=i){
                    pq2.push(costs[j--]);
                }
            }
        }


        return ans;
    }
};