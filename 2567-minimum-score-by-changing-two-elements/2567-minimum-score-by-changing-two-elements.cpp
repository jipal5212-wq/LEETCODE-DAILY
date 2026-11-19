class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 3) {
            return 0;
        }
        int diff = min({
            nums[n-1] - nums[2],  // Changin 2 smallest
            nums[n-2] - nums[1],  // Changing 1 smallest + 1 largest
            nums[n-3] - nums[0]   // Changing 2 largest
        });

        return diff;
    }
};