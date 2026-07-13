class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string c : tokens) {
            if (c != "+" && c != "-" && c != "*" && c != "/") {
                st.push(stoi(c));
                continue;
            }
            int second = st.top();
            st.pop();

            int first = st.top();
            st.pop();

            if (c == "+") {
                st.push(first + second);
            } else if (c == "-") {
                st.push(first - second);
            } else if (c == "*") {
                st.push(first * second);
            } else if (c == "/") {
                st.push(first / second);
            }
        }
        return st.top();
    }
};
