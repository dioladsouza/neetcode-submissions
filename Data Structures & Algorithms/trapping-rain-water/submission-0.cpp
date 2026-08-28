class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int leftMax = height[l], rightMax = height[r];
        int total = 0;
        while(l < r)
        {
            if(leftMax < rightMax)
            {
                l += 1;
                leftMax = max(leftMax, height[l]);
                total += leftMax - height[l];
            }
            else
            {
                r -= 1;
                rightMax = max(rightMax, height[r]);
                total += rightMax - height[r];
            }
        }
        return total;
    }
};
