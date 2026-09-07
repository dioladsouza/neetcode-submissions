class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(), max_count = 0;
        for(int i = 0; i < n; i++)
            max_count = max(max_count, piles[i]);
        int k = max_count;
        int low = 1, high = k;
        while(low <= high)
        {
            int mid = (low + high)/2;
            double hours = 0;
            for(int i = 0; i < n; i++)
                hours += ceil((double)piles[i]/mid);
            if(hours <= h)
            {
                k = min(k, mid);
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return k;
    }
};
