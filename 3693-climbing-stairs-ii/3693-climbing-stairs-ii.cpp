class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int j = 1; j <= n; j++) {
            if (j >= 1) {
                dp[j] = min(dp[j], dp[j - 1] + costs[j - 1] +
                                       (j - (j - 1)) * (j - (j - 1)));
            }
            if (j >= 2) {
                dp[j] = min(dp[j], dp[j - 2] + costs[j - 1] +
                                       (j - (j - 2)) * (j - (j - 2)));
            }
            if (j >= 3) {
                dp[j] = min(dp[j], dp[j - 3] + costs[j - 1] +
                                       (j - (j - 3)) * (j - (j - 3)));
            }
        }
        return dp[n];
    }
};