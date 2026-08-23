class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1, postfix = 1;
        int len = nums.size();
        vector<int> output(len, 1);
        for(int i = 0; i < len; i++)
        {
            output[i] = prefix;
            prefix *= nums[i];
        }
        for(int i = len - 1; i >= 0; i--)
        {
            output[i] *= postfix;
            postfix *= nums[i];
        }
        return output;
    }
};
