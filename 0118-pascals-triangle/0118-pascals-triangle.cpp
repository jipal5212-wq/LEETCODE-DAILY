class Solution {
public:
    vector<vector<int>> dp;
    vector<int> solve(int n) {
        if (n == 1)
            return {1};
        if (n == 2)
            return {1, 1};
        if (!dp[n].empty())
            return dp[n];
        vector<int> prev = solve(n - 1);
        vector<int> temp(n, 1);
        for (int j = 1; j < n - 1; j++) {
            temp[j] = prev[j - 1] + prev[j];
        }
        return dp[n] = temp;
    }
    vector<vector<int>> generate(int numRows) {
        dp.resize(numRows + 1);
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; i++) {
            ans.push_back(solve(i));
        }
        return ans;
    }
};