class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        // priority_queue<pair<int,int>> pq;
        // priority_queue<pair<int,int>> temp;
        // int n = profits.size();
        // for(int i=0;i<n;i++){
        //     pq.push({profits[i],capital[i]});
        // }

        // while(!pq.empty() && k>0){

        //     while(!pq.empty()){
        //         auto it = pq.top();
        //         pq.pop();
        //         if(it.second<=w){
        //             cout<<it.first<<endl;
        //             w+=it.first;
        //             break;
        //         }else{
        //             temp.push(it);
        //         }
        //     }

        //     while(!temp.empty()){
        //         pq.push(temp.top());
        //         temp.pop();
        //     }
        //     k--;
        // }
        // return w;
        

        int n = profits.size();
        vector<pair<int,int>> v(n);

        for(int i=0;i<n;i++){
            v[i] = {capital[i],profits[i]};
        }
        sort(v.begin(),v.end());

        priority_queue<int> maxHeap;
        int i=0;
        while(k--){
            while(i<n && v[i].first<=w){
                maxHeap.push(v[i].second);
                i++;
            }
            if(maxHeap.empty()){
                break;
            }
            w+=maxHeap.top();
            maxHeap.pop();
        }
        return w;
    }
};