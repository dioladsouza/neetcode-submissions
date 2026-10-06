class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> permutation;
        vector<vector<int>> res;
        vector<int> vis(nums.size(), 0);
        allPermutations(0, nums, vis, permutation, res);
        return res;
    }
private:
    void allPermutations(int idx, vector<int>& nums, vector<int>& vis,
    vector<int>& permutation, vector<vector<int>>& res)
    {
        //base case
        if(idx >= nums.size())
        {
            res.push_back(permutation);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(!vis[i])
            {
                vis[i] = 1;
                permutation.push_back(nums[i]);
                allPermutations(idx + 1, nums, vis, permutation, res);
                permutation.pop_back();
                vis[i] = 0;
            }
        }
    }
};
