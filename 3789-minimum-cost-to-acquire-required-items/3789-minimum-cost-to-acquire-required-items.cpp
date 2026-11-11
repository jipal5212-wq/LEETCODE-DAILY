class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {
        long long go = max(need1, need2);
        long long co = min(need1, need2);
        long long ans1 = 1LL * cost1 * need1 + 1LL * cost2 * need2;
        long long ans2 = go * costBoth;
        long long ans3 = co * costBoth;
        if (need1 > need2) {
            ans3 +=  1LL * (need1 - need2) * cost1;
        } else {
            ans3 += 1LL * (need2 - need1) * cost2;
        }
        long long final = min(ans1, min(ans2, ans3));

        return final;
    }
};