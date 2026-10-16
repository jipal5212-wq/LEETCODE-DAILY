class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        vector<long long> sum(4 * n, 0);
        vector<long long> sq(4 * n, 0);
        vector<long long> lazy(4 * n, 0);

        auto update = [&](auto&& self, int node, int l, int r, int ql, int qr,
                          long long val) -> void {
            if (ql <= l && r <= qr) {
                long long len = r - l + 1;
                sq[node] = (sq[node] + 2 * val % MOD * sum[node] % MOD +
                            val * val % MOD * len % MOD) %
                           MOD;
                sum[node] = (sum[node] + val * len) % MOD;
                lazy[node] = (lazy[node] + val) % MOD;
                return;
            }
            int mid = (l + r) / 2;

            if (lazy[node] != 0) {
                long long v = lazy[node];

                for (int child : {node * 2, node * 2 + 1}) {
                    int cl = (child == node * 2 ? l : mid + 1);
                    int cr = (child == node * 2 ? mid : r);
                    long long len = cr - cl + 1;

                    sq[child] = (sq[child] + 2 * v % MOD * sum[child] % MOD +
                                 v * v % MOD * len % MOD) %
                                MOD;
                    sum[child] = (sum[child] + v * len) % MOD;
                    lazy[child] = (lazy[child] + v) % MOD;
                }

                lazy[node] = 0;
            }

            if (ql <= mid)
                self(self, node * 2, l, mid, ql, qr, val);

            if (qr > mid)
                self(self, node * 2 + 1, mid + 1, r, ql, qr, val);

            sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
            sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
        };

        auto query = [&](auto&& self, int node, int l, int r) -> long long {
            return sq[node];
        };

        unordered_map<int, int> last;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int left = last.count(nums[i]) ? last[nums[i]] + 1 : 0;

            update(update, 1, 0, n - 1, left, i, 1);

            ans = (ans + sq[1]) % MOD;
            last[nums[i]] = i;
        }

        return ans;
    }
};