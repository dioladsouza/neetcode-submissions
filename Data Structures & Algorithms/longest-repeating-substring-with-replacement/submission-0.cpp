class Solution {
public:
    int characterReplacement(string s, int k) {
        //sliding window optimal - O(N * 26)
        int n = s.length();
        int result = 0;
        int l = 0, maxFreq = 0;
        vector<int> freq(26, 0);
        for(int r = 0; r < n; r++)
        {
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);
            while(r - l + 1 - maxFreq > k)
            {
                freq[s[l] - 'A']--;
                l++;
            }
            result = max(result, r - l + 1);
        }
        return result;
    }
};
