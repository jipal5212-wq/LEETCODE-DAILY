class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0, cost = 0;
        int j = n - 1;
        deque<pair<int, int>> dq;
        for (int i = n - 1; i >= 0; i--) {
            int cnt = 1;
            while (!dq.empty() && dq.back().first < nums[i]) {
                auto [val, c] = dq.back();
                dq.pop_back();
                cnt += c;
                cost += 1LL * (nums[i] - val) * c;
            }
            dq.push_back({nums[i], cnt});
            while (cost > k) {
                auto [val, c] = dq.front();
                dq.pop_front();
                cost -= val - nums[j];
                j--;
                if (c > 1)
                    dq.push_front({val, c - 1});
            }
            ans += j - i + 1;
        }
        return ans;
    }
};