class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReachIdx = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(maxReachIdx < i) 
                return false;
            else
                maxReachIdx = max(maxReachIdx, i + nums[i]);
        }
        return true;
    }
};