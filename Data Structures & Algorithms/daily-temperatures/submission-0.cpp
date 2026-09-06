class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector<int> result(len, 0);
        stack<pair<int, int>> st;
        for(int i = 0; i < len; i++)
        {
            while(!st.empty() && temperatures[i] > st.top().first)
            {
                result[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({temperatures[i], i});
        }
        return result;
    }
};
