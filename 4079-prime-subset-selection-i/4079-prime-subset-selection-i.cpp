class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<int> ans;
        int sum = 0;
        for (int i = 2; i <= n; i++) {
            bool prime = true;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    prime = false;
                    break;
                }
            }
            if (prime) {
                if (sum + i > s)
                    break;
                sum += i;
                ans.push_back(i);
            }
        }
        return ans;
    }
};