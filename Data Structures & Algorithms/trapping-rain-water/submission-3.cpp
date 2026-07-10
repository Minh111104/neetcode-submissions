class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int lMax = height[l];
        int rMax = height[r];
        int water = 0;

        while (l < r) {
            if (lMax < rMax) {
                l++;
                lMax = max(lMax, height[l]);
                water += (lMax - height[l]);
            } else {
                r--;
                rMax = max(rMax, height[r]);
                water += (rMax - height[r]);
            }
        }
        return water;
    }
};
