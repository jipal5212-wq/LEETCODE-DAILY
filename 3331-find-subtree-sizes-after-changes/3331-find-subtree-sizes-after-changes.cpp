class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n), newAdj(n);
        for (int i = 1; i < n; i++)
            adj[parent[i]].push_back(i);

        vector<int> last(26, -1), newParent(n, -1);
        function<void(int)> dfs = [&](int u) {
            int c = s[u] - 'a';
            int prev = last[c];
            newParent[u] = (prev != -1) ? prev : parent[u];
            last[c] = u;
            for (int v : adj[u])
                dfs(v);

            last[c] = prev;
        };

        dfs(0);
        for (int i = 1; i < n; i++)
            newAdj[newParent[i]].push_back(i);

        vector<int> order;
        stack<int> st;
        st.push(0);
        while (!st.empty()) {
            int u = st.top();
            st.pop();

            order.push_back(u);
            for (int v : newAdj[u])
                st.push(v);
        }
        vector<int> ans(n, 1);
        reverse(order.begin(), order.end());

        for (int u : order) {
            if (newParent[u] != -1)
                ans[newParent[u]] += ans[u];
        }

        return ans;
    }
};