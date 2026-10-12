class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {     // base case
            return 1;
        }
        
        vector<int> dp(n+1);    // store # of ways to climb
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];  // sum of 1 step and 2 steps
        }
        return dp[n];   // last cell of dp showing # of ways
    }
};