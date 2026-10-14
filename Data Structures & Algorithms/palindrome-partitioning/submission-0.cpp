class Solution {
private:
    void dfs(int idx, string s, vector<string>& path, vector<vector<string>>& res)
    {
        if(idx == s.size())
        {
            res.push_back(path);
            return;
        }
        for(int i = idx; i < s.size(); i++)
        {
            if(isPalindrome(s, idx, i))
            {
                path.push_back(s.substr(idx, i - idx + 1));
                dfs(i + 1, s, path, res);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int start, int end)
    {
        while(start <= end)
        {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        dfs(0, s, path, res);
        return res;
    }
};
