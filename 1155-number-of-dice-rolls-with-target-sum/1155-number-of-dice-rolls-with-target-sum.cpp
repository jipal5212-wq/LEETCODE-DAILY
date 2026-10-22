// including dp now
class Solution {
    int solve(int n, int k, int t, vector<vector<int>>& dp) {
        if (n == 0 && t == 0) {
            return 1;
        }
        if (n <= 0 || t <=0|| t>n*k) {
            return 0;
        }
        if (dp[n][t] != -1) {
            return dp[n][t];
        }
        int ans = 0;
        for (int i = 1; i <= k && i<=t; i++) {
            int a = solve(n - 1, k, t - i, dp);
            ans = (ans + a) % 1000000007;     
        }
        dp[n][t] = ans;
        return ans;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return solve(n, k, target, dp);
    }
};