class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        auto convert = [&](string s) {
            int total = 0;
            int month = stoi(s.substr(0, 2));
            int day = stoi(s.substr(3, 2));

            for (int i = 0; i < month - 1; i++)
                total += days[i];
            return total + day;
        };

        int start = max(convert(arriveAlice), convert(arriveBob));
        int end = min(convert(leaveAlice), convert(leaveBob));

        return max(0, end - start + 1);
    }
};