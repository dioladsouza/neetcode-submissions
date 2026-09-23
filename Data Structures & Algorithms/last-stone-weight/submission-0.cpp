class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(int i = 0; i < stones.size(); i++)
            maxHeap.push(stones[i]);
        while(maxHeap.size() > 1)
        {
            int stone1 = maxHeap.top();
            maxHeap.pop();
            int stone2 = maxHeap.top();
            maxHeap.pop();
            if(stone2 < stone1)
                maxHeap.push(stone1 - stone2);
        }
        if(!maxHeap.empty())
            return maxHeap.top();
        return 0;
    }
};
