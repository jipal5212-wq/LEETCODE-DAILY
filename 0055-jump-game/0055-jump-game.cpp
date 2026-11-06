class Solution {
public:
    bool canJump(vector<int>& nums) {
        int g = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= g)
                g = i;
        }
        return g == 0;
    }
};