class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];   // first value of the list
        int currentSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];

            if (currentSum > maxSum) {
                maxSum = currentSum;    // update maxSum
            }
            if (currentSum < 0) {
                currentSum = 0;     // reset
            }
        }
        return maxSum;
    }
};