class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(char ch : tasks)
            freq[ch - 'A']++;

        priority_queue<int> maxHeap;
        for(int i : freq)
        {
            if(i > 0)
                maxHeap.push(i);
        }

        int time = 0;
        queue<pair<int, int>> q;

        while(!maxHeap.empty() || !q.empty())
        {
            time += 1;
            if(!maxHeap.empty())
            {
                int top = maxHeap.top();
                maxHeap.pop();
                if(top - 1 > 0)
                    q.push({top - 1, time + n});
            }
            else
                time = q.front().second;
            if(!q.empty() && time == q.front().second)
            {
                int front = q.front().first;
                q.pop();
                maxHeap.push(front);
            }
        }
        return time;
    }
};