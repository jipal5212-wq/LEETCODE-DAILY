class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return INT_MAX;
        if (dp[amount] != -1)
            return dp[amount];
        int ans = INT_MAX;
        for (int coin : coins) {
            int sub = solve(coins, amount - coin, dp);
            if (sub != INT_MAX) {
                ans = min(ans, 1 + sub);
            }
        }
        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int ans = solve(coins, amount, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};