class Solution {
public:
    const int MOD = 1e9 + 7;
    int m, n;
    vector<vector<int>> g;
    vector<vector<vector<pair<int, int>>>> memo;
    vector<vector<vector<bool>>> vis;
    pair<int, int> resolve(int r, int c, int dir) {
        if (r >= m || c >= n)
            return {-1, -1};
        if (r == m - 1 && c == n - 1)
            return {r, c};
        if (g[r][c] == 0)
            return {r, c};
        if (vis[r][c][dir])
            return memo[r][c][dir];
        vis[r][c][dir] = true;
        if (dir == 0)
            memo[r][c][dir] = resolve(r + 1, c, 1);
        else
            memo[r][c][dir] = resolve(r, c + 1, 0);
        return memo[r][c][dir];
    }
    int uniquePaths(vector<vector<int>>& grid) {
        g = grid;
        m = g.size();
        n = g[0].size();
        memo.assign(m, vector<vector<pair<int, int>>>(
                           n, vector<pair<int, int>>(2, {-1, -1})));
        vis.assign(m, vector<vector<bool>>(n, vector<bool>(2, false)));
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] == 0)
                    continue;
                auto [x1, y1] = resolve(i, j + 1, 0);
                if (x1 != -1)
                    dp[x1][y1] = (dp[x1][y1] + dp[i][j]) % MOD;
                auto [x2, y2] = resolve(i + 1, j, 1);
                if (x2 != -1)
                    dp[x2][y2] = (dp[x2][y2] + dp[i][j]) % MOD;
            }
        }
        return dp[m - 1][n - 1];
    }
};