class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        const int NEG = -1e9;
        vector<int> dp(budget + 1, NEG);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            int f = items[i][0];
            int p = items[i][1];

            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (items[j][0] % f == 0)
                    cnt++;
            }
            vector<int> buy(budget + 1, NEG);
            for (int j = p; j <= budget; j++) {
                buy[j] = max(buy[j], dp[j - p] + cnt);

                if (buy[j - p] != NEG)
                    buy[j] = max(buy[j], buy[j - p] + 1);
            }
            for (int j = 0; j <= budget; j++)
                dp[j] = max(dp[j], buy[j]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};
