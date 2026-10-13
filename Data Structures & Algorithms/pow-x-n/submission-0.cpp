class Solution {
public:
    double helper(double x, int n) {
        // base case
        if (x == 0) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }

        double half = helper(x, n/2);
        half *= half;
        // handle odd n
        return (n % 2 != 0) ? half*x : half;
    }    
    
    double myPow(double x, int n) {
        double res = helper(x, abs(n));
        return (n >= 0) ? res : 1/res;
    }
};