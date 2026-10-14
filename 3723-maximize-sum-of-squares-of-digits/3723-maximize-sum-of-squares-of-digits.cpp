class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num)
            return "";
        string ans = "";
        while (num--) {
            int digit = min(9, sum);
            ans += to_string(digit);
            sum -= digit;
        }
        if (sum > 0)
            return "";
        return ans;
    }
};