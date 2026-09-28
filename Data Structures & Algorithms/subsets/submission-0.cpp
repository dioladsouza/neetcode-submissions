class Solution {
private:
    void dfs(vector<int>& nums, int idx, vector<vector<int>>& ans, vector<int>& subset)
    {
        if(idx >= nums.size())
        {
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[idx]);
        dfs(nums, idx + 1, ans, subset);
        subset.pop_back();
        dfs(nums, idx + 1, ans, subset);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        dfs(nums, 0, ans, subset);
        return ans;
    }
};
