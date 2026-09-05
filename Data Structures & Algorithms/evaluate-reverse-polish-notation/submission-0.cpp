class Solution {
public:
    int operations(int a, int b, char op)
    {
        switch(op){
            case '+': 
                return a + b;
                break;
            case '-':
                return a - b;
                break;
            case '*':
                return a * b;
                break;
            case '/':
                return a / b;
                break;
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int result;
        for(string str : tokens)
        {
            if(str != "+" && str != "-" && str != "*" && str != "/")
                st.push(stoi(str));
            else
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                result = operations(b, a, str[0]);
                st.push(result);
            }
        }
        return st.top();
    }
};
