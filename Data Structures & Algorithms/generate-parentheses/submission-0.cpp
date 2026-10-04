class Solution {
private:
    void generateParentheses(int n, int open, int close, string str, vector<string>& result)
    {
        if(open > n || close > n || close > open) return;
        if(open == n && close == n)
        {
            result.push_back(str);
            return;
        }
        generateParentheses(n, open + 1, close, str + '(', result);
        generateParentheses(n, open, close + 1, str + ')', result);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParentheses(n, 0, 0, "", result);
        return result;
    }
};
