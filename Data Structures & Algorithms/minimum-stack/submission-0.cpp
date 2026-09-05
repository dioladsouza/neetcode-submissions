class MinStack {
public:
    stack<int> st;
    stack<int> minSt;
    MinStack() {
        st = stack<int>{};
        minSt = stack<int>{};
    }
    
    void push(int val) {
        st.push(val);
        if(!minSt.empty())
            minSt.push(min(val, minSt.top()));
        else
            minSt.push(val);
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
