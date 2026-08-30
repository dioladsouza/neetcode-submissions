class Solution {
public:
    int brackets(char l, char r)
    {
        int a = l == '(' && r == ')';
        int b = l == '{' && r == '}';
        int c = l == '[' && r == ']';
        return a || b || c;
    }
    bool isValid(string s) {
        stack<int> st;
        for(char c : s)
        {
            if(c == '(' || c == '{' || c == '[')
                st.push(c);
            else if(st.empty() || !brackets(st.top(), c))
                return false;
            else
                st.pop();
        }
        if(st.empty())
            return true;
        return false;
    }
};
