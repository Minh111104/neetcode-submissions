class MinStack {
public:
    stack<int> st;
    stack<int> minSt;

    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);

        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }
    
    void pop() {
        if (minSt.top() == st.top()) {
            minSt.pop();
        }
        st.pop();        
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
