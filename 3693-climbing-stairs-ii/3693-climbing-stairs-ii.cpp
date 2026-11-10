class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int cost = INT_MAX;

            for (int j = i + 1; j <= min(n, i + 3); j++) {
                cost = min(cost, dp[j] + costs[j - 1] + (j - i) * (j - i));
            }
            dp[i] = cost;
        }
        return dp[0];
    }
};