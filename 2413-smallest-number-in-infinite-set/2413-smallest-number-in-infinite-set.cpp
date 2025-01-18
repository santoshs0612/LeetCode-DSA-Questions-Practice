class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>, greater<int>>pq;
    unordered_map<int,int> mp;
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++){
            pq.push(i);
            mp[i]++;
        }
        
    }
    
    int popSmallest() {
        int val =-1;
        val = pq.top();
        pq.pop();
        mp.erase(val);
        return val;
        
    }
    
    void addBack(int num) {
        
        if(mp.find(num)==mp.end()){
            mp[num]++;
            pq.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */