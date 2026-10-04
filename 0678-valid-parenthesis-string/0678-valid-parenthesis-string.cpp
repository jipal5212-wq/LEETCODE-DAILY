class Solution {
public:
    vector<vector<int>> dp;
    bool check(string& s, int i = 0, int count = 0) {
        if (count < 0)
            return false;
        if (i == s.size())
            return count == 0;
        if (dp[i][count] != -1)
            return dp[i][count];
        bool ans = false;
        if (s[i] == '(') {
            ans = check(s, i + 1, count + 1);
        } else if (s[i] == ')') {
            ans = check(s, i + 1, count - 1);
        } else {                                  
            bool o1 = check(s, i + 1, count + 1); 
            bool o2 = check(s, i + 1, count);     
            bool o3 = check(s, i + 1, count - 1); 
            ans = o1 || o2 || o3;
        }
        return dp[i][count] = ans;
    }
    bool checkValidString(string s) {
        int n = s.size();
        dp.assign(n, vector<int>(n + 1, -1));
        return check(s);
    }
};
