class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end(), [&](int a, int b) {
            int sa = digitSum(a);
            int sb = digitSum(b);

            if (sa == sb)
                return a < b;
            return sa < sb;
        });
        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[nums[i]] = i;
        }
        vector<bool> vis(n, false);
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] || pos[sorted[i]] == i)
                continue;
            int j = i;
            int cycleSize = 0;

            while (!vis[j]) {
                vis[j] = true;
                j = pos[sorted[j]];
                cycleSize++;
            }
            swaps += cycleSize - 1;
        }
        return swaps;
    }
};