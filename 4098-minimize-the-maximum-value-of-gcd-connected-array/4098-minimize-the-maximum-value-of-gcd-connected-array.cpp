class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        int p = value;
        for (int i = 2; 1LL * i * i <= value; i++) {
            if (value % i == 0) {
                p = i;
                break;
            }
        }
        long long left = 0;
        if (value % 2 == 0)
            left = (value - 1) / 2;
        else if (p != value)
            left = (value - p + 1) / 2;
        if (index > left)
            return -1;
        long long right = n - index - 1;
        if (value == 1)
            return (right == 0) ? 1 : -1;
        if (right == 0)
            return value;
        if (value % 2 == 0)
            return 1LL * value + 2 * right;
        return 1LL * value + p + 2 * (right - 1);
    }
};