class Solution {
private:
    void allCombinations(int idx, int target, vector<int>& nums, vector<int>& combination, vector<vector<int>>& ans)
    {
        if(idx == nums.size())
        {
            if(target == 0)
                ans.push_back(combination);
            return;
        }
        if(nums[idx] <= target)
        {
            combination.push_back(nums[idx]);
            allCombinations(idx, target - nums[idx], nums, combination, ans);
            combination.pop_back();
        }
        allCombinations(idx + 1, target, nums, combination, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        allCombinations(0, target, nums, combination, ans);
        return ans;
    }
};