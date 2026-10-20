class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> desc(n, 0), premax(n), sufmin(n);
        for (int i = 1; i < n; i++)
            desc[i] = desc[i - 1] + (nums[i - 1] > nums[i]);
        premax[0] = nums[0];
        for (int i = 1; i < n; i++)
            premax[i] = max(premax[i - 1], nums[i]);
        sufmin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            sufmin[i] = min(sufmin[i + 1], nums[i]);
        vector<bool> cut(n, true);
        for (int m = 1; m < n; m++)
            cut[m] = premax[m - 1] <= sufmin[m];
        auto rotatable = [&](int l, int r) {
            return desc[r] - desc[l] + (nums[r] > nums[l]) <= 1;
        };
        int ans = 0;
        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;
            bool valid = true;
            for (int l = 0; l < n; l += k) {
                if (!cut[l] || !rotatable(l, l + k - 1)) {
                    valid = false;
                    break;
                }
            }
            if (valid)
                ans += k;
        }
        return ans;
    }
};