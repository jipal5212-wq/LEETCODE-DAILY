class Solution {
public:
    bool checkString(string s) {
        int k = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'b') {
                k = 1;
            }
            if (k == 1 && s[i] == 'a') {
                return false;
            }
        }
        return true;
    }
};