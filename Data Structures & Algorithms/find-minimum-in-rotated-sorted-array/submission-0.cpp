class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int min_ele = INT_MAX;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(nums[low] <= nums[mid])
            {
                min_ele = min(min_ele, nums[low]);
                low = mid + 1;
            }
            else if(nums[mid] <= nums[high])
            {
                min_ele = min(min_ele, nums[mid]);
                high = mid - 1;
            }
        }
        return min_ele;
    }
};
