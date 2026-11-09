class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int row = 0, col = 0;
                    for (int k = 0; k < n; k++) {
                        if (grid[i][k] == 1)
                            row++;
                    }
                    for (int k = 0; k < m; k++) {
                        if (grid[k][j] == 1)
                            col++;
                    }

                    if (row > 1 || col > 1) {
                        ans++;
                    }

                    visited[i][j] = 1;
                }
            }
        }
        return ans;
    }
};