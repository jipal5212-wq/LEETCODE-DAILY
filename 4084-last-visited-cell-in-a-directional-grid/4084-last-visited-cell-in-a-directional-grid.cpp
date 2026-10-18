class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int p1 = 0;
        int p2 = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        while (true) {
            if (grid[p1][p2] == 'L') {
                if (p2 - 1 < 0 || vis[p1][p2 - 1] == 1) {
                    break;
                } else
                    vis[p1][p2] = 1;
                p2--;
            } else if (grid[p1][p2] == 'R') {
                if (p2 + 1 >= n || vis[p1][p2 + 1] == 1) {
                    break;
                } else
                    vis[p1][p2] = 1;
                p2++;
            } else if (grid[p1][p2] == 'U') {
                if (p1 - 1 < 0 || vis[p1 - 1][p2] == 1) {
                    break;
                } else
                    vis[p1][p2] = 1;
                p1--;
                ;
            } else {
                if (p1 + 1 >= m || vis[p1 + 1][p2] == 1) {
                    break;
                } else
                    vis[p1][p2] = 1;
                p1++;
            }
        }
        return {p1, p2};
    }
};