class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 2, 0);
        for (int i = n - 1; i >= 0; i--) {
            int a = dp[i + 2];
         int b = dp[i + 1];
            dp[i] = max(nums[i] + a, b);
        }
        return dp[0];
    }
};