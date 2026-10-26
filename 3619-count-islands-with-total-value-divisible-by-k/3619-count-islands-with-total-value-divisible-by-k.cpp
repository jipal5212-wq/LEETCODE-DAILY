class Solution {
    long long dfs(vector<vector<int>>& grid, int r, int c, int k) {
        long long ans = 0;
        if (r >= grid.size() || r < 0 || c >= grid[0].size() || c < 0 ||
            grid[r][c] == 0) {
            return 0;
        }
        ans = grid[r][c];
        grid[r][c] = 0;
        ans += dfs(grid, r, c - 1, k);
        ans += dfs(grid, r, c + 1, k);
        ans += dfs(grid, r + 1, c, k);
        ans += dfs(grid, r - 1, c, k);
        return ans;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    if (dfs(grid, i, j, k) % k == 0) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};