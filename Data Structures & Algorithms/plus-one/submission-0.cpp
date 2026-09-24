class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int carry = 1;

        for (int i = digits.size() - 1; i >= 0; --i) {
            digits[i] += carry;

            if (digits[i] < 10) {
                return digits;
            }

            carry = 1;      // digits[i] / 10;
            digits[i] = 0;  // digits[i] % 10
            res.push_back(0);
        }

        if (carry > 0) {
            res.push_back(carry);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};