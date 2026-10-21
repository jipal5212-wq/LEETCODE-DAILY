class Solution {
    vector<int> dp;
    int solve(vector<int>nums, int i) {
        if (i >= nums.size()) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int a = solve(nums, i + 2);
        int b = solve(nums, i + 1);
        int ans = max(nums[i]+a, b);
        dp[i]=ans;

        return ans;
    }
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        dp.assign(n + 1, -1);
        int i = 0;
        return solve(nums, i);
    }
};