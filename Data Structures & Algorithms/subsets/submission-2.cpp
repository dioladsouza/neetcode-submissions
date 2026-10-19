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
        allSubsets(idx + 1, nums, subset, result);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> result;
        allSubsets(0, nums, subset, result);
        return result;
    }
};