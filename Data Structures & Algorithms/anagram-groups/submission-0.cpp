class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        //key is string of character count, value is array of strings
        unordered_map<string, vector<string>> mpp;
        for(string s:strs)
        {
            vector<int> count_freq(26, 0);
            for(char c : s)
            {
                count_freq[c - 'a']++;
            }
            string key = to_string(count_freq[0]);
            for(int i = 1; i < 26; i++)
                key += ',' + to_string(count_freq[i]);
            mpp[key].push_back(s);
        }
        vector<vector<string>> result;
        for(const auto& pair:mpp)
        {
            result.push_back(pair.second);
        }
        return result;
    }
};
