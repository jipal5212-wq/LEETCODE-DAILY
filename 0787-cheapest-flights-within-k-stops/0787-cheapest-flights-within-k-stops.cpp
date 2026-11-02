class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        for (int i = 0; i <= k; i++) {
            vector<int> temp = dist;
            for (auto& f : flights) {
                int u = f[0];
                int v = f[1];
                int w = f[2];
                if (dist[u] != 1e9) {
                    temp[v] = min(temp[v], dist[u] + w);
                }
            }
            dist = temp;
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};