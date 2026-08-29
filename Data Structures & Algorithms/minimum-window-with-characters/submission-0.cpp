class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        if(m < n || n == 0) return "";
        unordered_map<char, int> freqT, window;
        for(char c : t)
            freqT[c]++;
        int l = 0;
        int have = freqT.size(), need = 0;
        int minLen = INT_MAX;
        pair<int, int> result = {-1, -1};
        for(int r = 0; r < m; r++)
        {
            window[s[r]]++;
            if(freqT.find(s[r]) != freqT.end() && window[s[r]] == freqT[s[r]])
                need++;
            
            while(have == need)
            {
                if(r - l + 1 < minLen)
                {
                    minLen = min(minLen, r - l + 1);
                    result = {l, r};
                }
                window[s[l]]--;
                if(freqT.find(s[l]) != freqT.end() && window[s[l]] < freqT[s[l]])
                    need--;
                l++;
            }
        }
        return minLen != INT_MAX? s.substr(result.first, minLen) : "";
    }
};
