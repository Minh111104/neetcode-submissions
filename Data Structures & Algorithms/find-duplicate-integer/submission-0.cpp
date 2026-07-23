class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Find a meeting point inside the cycle
        int slow = 0;
        int fast = 0;

        while (true) {
            slow = nums[slow]; // Move one step
            fast = nums[nums[fast]]; // Move two steps

            if (slow == fast) {
                break;
            }
        }
        int slow2 = 0; // Find the cycle entrance

        while (slow != slow2) {
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        return slow; // The cycle entrance is the duplicate number
    }
};
