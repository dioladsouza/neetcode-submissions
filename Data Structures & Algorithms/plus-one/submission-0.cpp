class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for(int i = n - 1; i >= 0; i--)
        {
            int sum = digits[i] + 1;
            if(sum < 10)
            {
                digits[i] = sum;
                return digits;
            }
            else
                digits[i] = sum % 10;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
