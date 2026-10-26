class Solution {

    bool dfs(vector<vector<int>>& grid, int r, int c) {
        if (r >= grid.size() || r < 0 || c >= grid[0].size() || c < 0) {
            return false;
        }
        if (grid[r][c] == 1) {
            return true;
        }
        grid[r][c] = 1;
        bool ld = dfs(grid, r, c - 1);
        bool rd = dfs(grid, r, c + 1);
        bool ud = dfs(grid, r - 1, c);
        bool dd = dfs(grid, r + 1, c);

        return (ld && rd && ud && dd);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i= 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    if (dfs(grid, i, j) == true) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};