class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //using min heap | TC: O(nlogk), SC: O(k)
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(auto& n :  nums)
        {
            minHeap.push(n);
            if(minHeap.size() > k)
                minHeap.pop();
        }
        return minHeap.top();
    }
};