class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for(int i = 0; i < n; i++)
            mpp[nums[i]]++;
        vector<pair<int, int>> arr;
        for(const auto& it:mpp)
            arr.push_back(it);
        sort(arr.begin(), arr.end(), 
        [](pair<int, int>& a, pair<int, int>& b)
        {   return a.second > b.second;});
        vector<int> result;
        for(int i = 0; i < k; i++)
            result.push_back(arr[i].first);
        return result;
    }
};
