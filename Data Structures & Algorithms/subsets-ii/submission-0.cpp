class Solution {
private:
    void allSubsets(int idx, vector<int>& nums, vector<int>& subset, set<vector<int>>& ans)
    {
        if(idx >= nums.size())
        {
            ans.insert(subset);
            return;
        }
        subset.push_back(nums[idx]);
        allSubsets(idx + 1, nums, subset, ans);
        subset.pop_back();
        allSubsets(idx + 1, nums, subset, ans);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        set<vector<int>> ans;
        allSubsets(0, nums, subset, ans);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};