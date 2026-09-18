class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq1(128, 0);
        int unique = 0;
        for (char c : t) {
            if (freq1[c] == 0) {
                unique++;
            }
            freq1[c]++;
        }
        vector<int> freq2(128, 0);
        int l = 0;
        int h = 0;
        int si = -1;
        int ei = -1;
        int length = INT_MAX;
        while (h < s.size()) {
            freq2[s[h]]++;
            if (freq1[s[h]] == freq2[s[h]]) {
                unique--;
            }
            h++;
            while (unique == 0) {
                if (h - l < length) {
                    length = h - l;
                    si = l;
                    ei = h;
                }
                if (freq1[s[l]] == freq2[s[l]]) {
                    unique++;
                }
                freq2[s[l]]--;
                l++;
            }
        }
        if (si == -1) {
            return "";
        }
        return s.substr(si, length);
    }
};
