class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char,int> mp;
        for(char &it: tasks){
            mp[it]++;
        }
        priority_queue<int> pq;

        for(auto &it: mp){
            pq.push(it.second);
        }
        int time=0;
        while(!pq.empty()){
            vector<int> temp;
            for(int i=0;i<=n;i++){
                if(!pq.empty()){
                    int c = pq.top();
                    pq.pop();
                    c--;
                    temp.push_back(c);
                }
            }
            for(auto a:temp){
                if(a>0){
                    pq.push(a);
                }
            }
            if(pq.empty()){
                time+=temp.size();
                
            }else{
                time+=n+1;
            }
        }
        return time;
    }
};