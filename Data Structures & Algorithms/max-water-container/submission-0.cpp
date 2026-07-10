class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int water = 0;

        while (l < r) {
            int heightVal = min(heights[l], heights[r]);
            int widthVal = r - l;

            water = max(water, heightVal * widthVal);

            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return water;
    }
};
