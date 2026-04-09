class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> smallHeap; 
    priority_queue<int, vector<int>, greater<int>> largeHeap;
    
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        smallHeap.push(num);
        
        // If the max in small heap is greater than the min in the large heap
        if(smallHeap.size() && largeHeap.size() && smallHeap.top() > largeHeap.top()){
            int val = smallHeap.top();
            smallHeap.pop();
            largeHeap.push(val);
        }
        
        // If size diff is more than 1
        if(smallHeap.size() > largeHeap.size() + 1){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if(largeHeap.size() > smallHeap.size() + 1){
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }
    
    double findMedian() {
        int n = smallHeap.size(), m = largeHeap.size();
        
        if(n > m){
            return smallHeap.top();
        }
        else if(m > n){
            return largeHeap.top();
        }
        else{
            return (smallHeap.top() + largeHeap.top()) / 2.0f;
        }
    }
};