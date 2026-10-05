class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1;
        int h = *max_element(nums.begin(), nums.end());
        while (l <= h) {
            int m = l + (h - l) / 2;
            long long cnt = 0;
            for (int i = 0; i < nums.size(); i++) {

                if (nums[i] % m == 0) {
                    cnt += (nums[i] / m) - 1;
                } else {
                    cnt += nums[i] / m;
                }
            }
            if (cnt > maxOperations) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        return l;
    }
};