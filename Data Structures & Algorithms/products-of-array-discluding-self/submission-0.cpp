class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix{1};
        vector<int> suffix{1};
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            prefix.push_back(prefix.back() * nums[i]);
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            suffix.push_back(suffix.back() * nums[i]);
        }

        for (int i = 0; i < nums.size(); i++) {
            res.push_back(prefix[i] * suffix[nums.size() - 1 - i]);
        }
        return res;
    }
};
