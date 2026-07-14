class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1; // minimum possible speed
        int r = *max_element(piles.begin(), piles.end()); // maximum needed speed (Find the iterator to the largest element, then read its value)
        int res = r; // at least maximum speed works

        while (l <= r) {
            int mid = l + (r - l) / 2; // current speed to test
            long long totalTime = 0;

            for (int p : piles) {
                totalTime += ceil((double)(p) / mid); // time = # of piles / speed
            }

            if (totalTime <= h) {
                res = mid; // this speed works, so record it
                r = mid - 1; // start looking for smaller rate
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};
