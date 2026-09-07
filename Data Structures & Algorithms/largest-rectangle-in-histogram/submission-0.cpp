class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int, int>> st;
        int max_area = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            int start = i;
            while(!st.empty() && heights[i] < st.top().second)
            {
                int height = st.top().second;
                int width = i - st.top().first;
                start = st.top().first;
                max_area = max(max_area, height * width);
                st.pop();
            }
            st.push({start, heights[i]});
        }
        while(!st.empty())
        {
            int height = st.top().second;
            int width = n - st.top().first; 
            max_area = max(max_area, height * width);
            st.pop();
        }
        return max_area;
    }
};
