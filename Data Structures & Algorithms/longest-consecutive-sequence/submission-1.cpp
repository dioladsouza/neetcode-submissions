class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        int max_len = 1;
        unordered_set<int> num_set;
        for(int i = 0; i < len ; i++)
            num_set.insert(nums[i]);
        for(auto it:num_set)
        {
            if(num_set.find(it - 1) == num_set.end())
            {
                int count = 1;
                int ele = it;
                while(num_set.find(ele + 1) != num_set.end())
                {
                    count++;
                    ele++;
                }
                max_len = max(max_len, count);
            }
        }
        return max_len;
    }
};
