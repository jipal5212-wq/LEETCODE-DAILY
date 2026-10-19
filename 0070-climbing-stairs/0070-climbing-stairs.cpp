class Solution {
    vector<int> dp;
    int solve(int n) {
        if (n <= 2)
            return n;
        if (dp[n] != -1)
            return dp[n];

        return dp[n] = solve(n - 1) + solve(n - 2);
    }

public:
    int climbStairs(int n) {
        dp.assign(n + 1, -1);
        return solve(n);
    }
};