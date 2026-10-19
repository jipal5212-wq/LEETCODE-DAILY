class Solution {
public:
    bool threeFibonacciSum(int n) {
        long long a = 0;
        long long b = 1;
        long long c = 1;
        while (a + b + c < n) {
            long long next = a + b + c;
            a = b;
            b = c;
            c =a+b;
        }
        return a + b + c == n;
    }
};