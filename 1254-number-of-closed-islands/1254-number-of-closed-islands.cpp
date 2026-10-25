class Solution {
public:
    int n, m;

    void dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 1)
            return;
        grid[i][j] = 1;
        dfs(i + 1, j, grid);
        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i, j - 1, grid);
    }
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for (int i = 0; i < n; i++) {
            dfs(i, 0, grid);
            dfs(i, m - 1, grid);
        }
        for (int j = 0; j < m; j++) {
            dfs(0, j, grid);
            dfs(n - 1, j, grid);
        }
        int cnt = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (grid[i][j] == 0) {
                    cnt++;
                    dfs(i, j, grid);
                }
            }
        }
        return cnt;
    }
};