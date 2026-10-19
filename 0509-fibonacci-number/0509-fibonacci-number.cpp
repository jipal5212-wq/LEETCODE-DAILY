class Solution {
    int solve(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1 || n == 2) {
            return 1;
        }
        return solve(n - 1) + solve(n - 2);
    }

public:
    int fib(int n) { return solve(n); }
};