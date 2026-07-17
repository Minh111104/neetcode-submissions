class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res(nums.size() - k + 1); // # of windows
        deque<int> dq; // store indices of elements in decreasing order of their values
        int l = 0;
        int r = 0;

        while (r < nums.size()) {
            while (!dq.empty() && nums[dq.back()] < nums[r]) {
                dq.pop_back(); // remove smaller values from the back
            }
            dq.push_back(r);

            if (!dq.empty() && dq.front() < l) { // check if the maximum candidate at the front is left of the current window
                dq.pop_front();
            }

            if ((r + 1) >= k) { // check if the first window is complete
                res[l] = nums[dq.front()]; // because the deque is decreasing, the front always points to the largest value in the current window
                l++;
            }
            r++;
        }
        return res;
    }
};
