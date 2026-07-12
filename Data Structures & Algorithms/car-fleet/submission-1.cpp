class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;

        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end(), greater<pair<int,int>>());
        stack<double> st;

        for (auto it : cars) {
            int pos = it.first;
            int spd = it.second;
            double timeTaken = (double)(target - pos) / spd;

            if (st.empty() || timeTaken > st.top()) {
                st.push(timeTaken);
            }
        }
        return st.size();
    }
};
