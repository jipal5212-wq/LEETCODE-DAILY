class Solution {
public:
    vector<int> dp;
    int solve(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2){
       return 1;     
        } 
        if (dp[n] != -1){
           return dp[n];  
        }    
        int a = solve(n - 1);
        int b = solve(n - 2);
        return dp[n] = a + b;
    }
    int fib(int n) {
        dp.assign(n + 1, -1);
        return solve(n);
    }
};