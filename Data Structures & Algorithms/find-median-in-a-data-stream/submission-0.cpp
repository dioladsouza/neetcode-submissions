class MedianFinder {
private:
    priority_queue<int> smallHeap; //max heap
    priority_queue<int, vector<int>, greater<int>> largeHeap; //min heap
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        smallHeap.push(num);

        //check if max in small heap <= min in large heap
        if(!largeHeap.empty() &&
            smallHeap.top() > largeHeap.top())
            {
                largeHeap.push(smallHeap.top());
                smallHeap.pop();
            }
        
        if(smallHeap.size() > largeHeap.size() + 1)
        {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if(largeHeap.size() > smallHeap.size() + 1)
        {
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }
    
    double findMedian() {
        if(smallHeap.size() > largeHeap.size())
            return smallHeap.top();
        else if(largeHeap.size() > smallHeap.size())
            return largeHeap.top();
        return (smallHeap.top() + largeHeap.top())/2.0;
    }
};
