class Solution {
private:
    void allSubsets(int idx, vector<int>& nums, vector<int>& subset, vector<vector<int>>& result)
    {
        if(idx == nums.size())
        {
            result.push_back(subset);
            return;
        }
        subset.push_back(nums[idx]);
        allSubsets(idx + 1, nums, subset, result);
        subset.pop_back();
        while(idx + 1 < nums.size() && nums[idx] == nums[idx + 1])
            idx++;
        allSubsets(idx + 1, nums, subset, result);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        vector<vector<int>> result;
        allSubsets(0, nums, subset, result);
        return result;
    }
};