class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(),
             [](int a, int b) { return abs(a) < abs(b); });
        int n = nums.size();
        long long ans = 0;
        for (int i = 0; i < n / 2; i++) {
            long long x = nums[n - 1 - i];
            long long y = nums[i];
            ans += x * x - y * y;
        }
        if (n % 2 == 1) {
            long long x = nums[n / 2];
            ans += x * x;
        }
        return ans;
    }
};