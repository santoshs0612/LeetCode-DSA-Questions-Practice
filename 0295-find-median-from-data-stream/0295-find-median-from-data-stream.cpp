class MedianFinder {
    private:    
        priority_queue<int> maxHeap;
        priority_queue<int,vector<int>,greater<int>> minHeap;
public:
    MedianFinder() {
        
    }

    void addNum(int num) {

        if(maxHeap.size()==0 || maxHeap.top()> num){
            maxHeap.push(num);
        }else{
            minHeap.push(num);
        }
        if(minHeap.size()+1< maxHeap.size()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }if(minHeap.size() >maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(minHeap.size()>maxHeap.size()){
            return maxHeap.top();
        }if(minHeap.size()<maxHeap.size()){
            return maxHeap.top();
        }
        return (minHeap.top()+maxHeap.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */