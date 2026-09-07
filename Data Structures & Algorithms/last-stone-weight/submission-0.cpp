class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        while (pq.size() > 1) {
            int stone1 = pq.top(); // take the biggest stone from the heap
            pq.pop();
            int stone2 = pq.top();
            pq.pop();

            if (stone1 != stone2) {
                pq.push(abs(stone1 - stone2));
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};