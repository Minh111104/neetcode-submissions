class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);

        // Count frequency of tasks
        for (char task : tasks) {
            count[task - 'A']++;
        }
        // Build a max-heap
        priority_queue<int> maxHeap;
        
        for (int cnt : count) {
            if (cnt > 0) {
                maxHeap.push(cnt);
            }
        }
        // Define time and cooldown queue
        int time = 0;
        queue<pair<int, int>> q; // {remaining_count, available_time}
        
        while (!maxHeap.empty() || !q.empty()) {
            time++;

            // Case 1: Heap is empty → jump forward in time
            if (maxHeap.empty()) {
                time = q.front().second;
            } 
            // Case 2: Run a task from heap
            else {
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();
                if (cnt > 0) {
                    q.push({cnt, time + n});
                }
            }
            // Case 3: Move tasks back from cooldown to heap
            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};