class Solution {
private:
    vector<string> res;
    vector<string> digitMapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void backtrackFunc(int i, string currentStr, string &digits)
        {
            if(currentStr.size() == digits.size())
            {
                res.push_back(currentStr);
                return;
            }
    
            for(char c : digitMapping[digits[i] - '0'])
            {
                backtrackFunc(i + 1, currentStr + c, digits);
            }
        }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};

        backtrackFunc(0, "", digits);
        return res;
    }
};