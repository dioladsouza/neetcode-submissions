class Solution {
private:
    void allPermutations(vector<int>& nums, vector<int>& permutation, int freq[], vector<vector<int>>& result)
    {
        if(permutation.size() == nums.size())
        {
            result.push_back(permutation);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(!freq[i])
            {
                permutation.push_back(nums[i]);
                freq[i] = 1;
                allPermutations(nums, permutation, freq, result);
                freq[i] = 0;
                permutation.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> permutation;
        int freq[nums.size()];
        for(int i = 0; i < nums.size(); i++)
            freq[i] = 0;
        allPermutations(nums, permutation, freq, result);
        return result;
    }
};