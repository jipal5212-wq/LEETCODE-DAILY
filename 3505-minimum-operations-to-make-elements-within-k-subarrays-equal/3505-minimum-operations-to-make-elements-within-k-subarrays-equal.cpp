
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> cost(n - x + 1);
        multiset<int> left, right;
        long long sumL = 0, sumR = 0;
        auto balance = [&]() {
            while (left.size() > right.size() + 1) {
                int val = *left.rbegin();
                left.erase(left.find(val));
                sumL -= val;
                right.insert(val);
                sumR += val;
            }
            while (left.size() < right.size()) {
                int val = *right.begin();
                right.erase(right.find(val));
                sumR -= val;
                left.insert(val);
                sumL += val;
            }
        };
        auto add = [&](int val) {
            if (left.empty() || val <= *left.rbegin()) {
                left.insert(val);
                sumL += val;
            } else {
                right.insert(val);
                sumR += val;
            }
            balance();
        };
        auto remove = [&](int val) {
            auto it = left.find(val);
            if (it != left.end()) {
                left.erase(it);
                sumL -= val;
            } else {
                it = right.find(val);
                right.erase(it);
                sumR -= val;
            }
            balance();
        };
        auto getCost = [&]() -> long long {
            long long median = *left.rbegin();
            return median * left.size() - sumL + sumR - median * right.size();
        };
        for (int i = 0; i < x; i++)
            add(nums[i]);
        cost[0] = getCost();
        for (int i = x; i < n; i++) {
            remove(nums[i - x]);
            add(nums[i]);
            cost[i - x + 1] = getCost();
        }
        const long long INF = 1e18;
        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, INF));
        dp[0][0] = 0;
        for (int j = 0; j <= k; j++) {
            for (int i = 0; i <= n; i++) {
                if (dp[j][i] == INF)
                    continue;
                if (i < n)
                    dp[j][i + 1] = min(dp[j][i + 1], dp[j][i]);
                if (j < k && i + x <= n) {
                    dp[j + 1][i + x] =
                        min(dp[j + 1][i + x], dp[j][i] + cost[i]);
                }
            }
        }
        return dp[k][n];
    }
};
