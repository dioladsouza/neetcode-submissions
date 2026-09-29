class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 0;
        int prev1 = 1;
        for (int i = 0; i < n; ++i) {
            //current Fibonacci number: F(i) = F(i-1) + F(i-2)
            int current = prev2 + prev1;
          
            //move forward by one position
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};