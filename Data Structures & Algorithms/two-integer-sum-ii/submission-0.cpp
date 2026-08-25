class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left_ptr = 0, right_ptr = n - 1;
        while(left_ptr < right_ptr)
        {
            if(numbers[left_ptr] + numbers[right_ptr] > target)
                right_ptr--;
            else if(numbers[left_ptr] + numbers[right_ptr] < target)
                left_ptr++;
            else
                return {left_ptr + 1, right_ptr + 1};
        }
        return {};
    }
};
