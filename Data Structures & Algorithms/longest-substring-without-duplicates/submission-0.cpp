class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if(len == 0) return 0;
        int result = 0;
        int ptr = 0;
        unordered_map<char, int> mpp;
        for(int i = 0; i < len; i++)
        {
            mpp[s[i]]++;
            while(mpp[s[i]] > 1)
            {
                mpp[s[ptr]]--;
                ptr++;
            }
            result = max(result, i - ptr + 1);
        }
        return result;
    }
};
