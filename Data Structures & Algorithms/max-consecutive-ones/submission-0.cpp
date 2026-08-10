class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currentNum = 0;
        int maxNum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                currentNum++;
            }
            else {
                maxNum = max(currentNum, maxNum);   // update maxNum
                currentNum = 0;                     // reset currentNum for next loop
            }
        }
        maxNum = max(currentNum, maxNum);
        
        return maxNum;
    }
};