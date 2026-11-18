class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
            nums[i] += (1001 * (nums[nums[i]] % 1001));
        for (int i = 0; i < nums.size(); i++)
            nums[i] /= 1001;
        return nums;
    }
};