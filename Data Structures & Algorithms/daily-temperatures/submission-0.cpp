class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> res(temperatures.size(), 0);

        for (int curIdx = 0; curIdx < temperatures.size(); curIdx++) {
            while (!st.empty() && temperatures[curIdx] > temperatures[st.top()]) {
                int prevIdx = st.top();

                st.pop();
                res[prevIdx] = curIdx - prevIdx;
            }
            st.push(curIdx);
        }
        return res;
    }
};
