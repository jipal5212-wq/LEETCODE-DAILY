class Solution {
public:
    int solve(int n, int i, vector<int>& costs, vector<int>& dp) {
        if (i == n) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int a = INT_MAX, b = INT_MAX, c = INT_MAX;
        if (i + 1 <= n) {
            a = costs[i] + 1 + solve(n, i + 1, costs, dp);
        }
        if (i + 2 <= n) {
            b = costs[i + 1] + 4 + solve(n, i + 2, costs, dp);
        }

        if (i + 3 <= n) {
            c = costs[i + 2] + 9 + solve(n, i + 3, costs, dp);
        }
        return dp[i] = min(a, min(b, c));
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, -1);
        return solve(n, 0, costs, dp);
    }
};