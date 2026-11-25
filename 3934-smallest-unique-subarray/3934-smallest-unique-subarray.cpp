class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> names{nums};

        for (int half = 1; 2 * half <= n; half *= 2) {
            unordered_map<long long, int> ids;
            vector<int> whole;

            for (auto [a, b] :
                 views::zip(names.back(), names.back() | views::drop(half))) {
                whole.push_back(
                    ids.try_emplace((long long)a << 32 | b, ids.size())
                        .first->second);
            }

            names.push_back(move(whole));
        }

        auto found = [&](int length) {
            int k = bit_width((unsigned)length) - 1;
            unordered_map<long long, int> count;

            for (auto [a, b] : views::zip(
                     names[k], names[k] | views::drop(length - (1 << k)))) {
                count[(long long)a << 32 | b]++;
            }

            return ranges::any_of(
                count, [](auto& entry) { return entry.second == 1; });
        };

        return *ranges::partition_point(views::iota(1, n), not_fn(found));
    }
};