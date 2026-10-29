// itna lamba solution ..aukaat ke bahar ka question 
class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s,
                                vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> parent(n, -1), depth(n), sz(n), heavy(n, -1);
        vector<int> head(n), pos(n);
        int timer = 0;

        function<void(int, int)> dfs1 = [&](int u, int p) {
            parent[u] = p;
            sz[u] = 1;
            int mx = 0;

            for (int v : adj[u]) {
                if (v == p)
                    continue;
                depth[v] = depth[u] + 1;
                dfs1(v, u);
                sz[u] += sz[v];

                if (sz[v] > mx) {
                    mx = sz[v];
                    heavy[u] = v;
                }
            }
        };
        function<void(int, int)> dfs2 = [&](int u, int h) {
            head[u] = h;
            pos[u] = timer++;

            if (heavy[u] != -1)
                dfs2(heavy[u], h);

            for (int v : adj[u]) {
                if (v == parent[u] || v == heavy[u])
                    continue;
                dfs2(v, v);
            }
        };
        dfs1(0, -1);
        dfs2(0, 0);

        vector<int> seg(4 * n, 0);

        function<void(int, int, int)> build = [&](int node, int l, int r) {
            if (l == r) {
                int u = 0;
                for (; pos[u] != l; u++) {
                }
                seg[node] = 1 << (s[u] - 'a');
                return;
            }

            int mid = (l + r) / 2;
            build(node * 2, l, mid);
            build(node * 2 + 1, mid + 1, r);
            seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
        };
        vector<int> rev(n);
        for (int u = 0; u < n; u++)
            rev[pos[u]] = u;

        function<void(int, int, int)> buildTree = [&](int node, int l, int r) {
            if (l == r) {
                int u = rev[l];
                seg[node] = 1 << (s[u] - 'a');
                return;
            }
            int mid = (l + r) / 2;
            buildTree(node * 2, l, mid);
            buildTree(node * 2 + 1, mid + 1, r);
            seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
        };
        function<void(int, int, int, int, int)> update =
            [&](int node, int l, int r, int idx, int val) {
                if (l == r) {
                    seg[node] = val;
                    return;
                }
                int mid = (l + r) / 2;
                if (idx <= mid)
                    update(node * 2, l, mid, idx, val);
                else
                    update(node * 2 + 1, mid + 1, r, idx, val);

                seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
            };
        function<int(int, int, int, int, int)> query =
            [&](int node, int l, int r, int ql, int qr) -> int {
            if (ql <= l && r <= qr)
                return seg[node];

            int mid = (l + r) / 2;
            int ans = 0;
            if (ql <= mid)
                ans ^= query(node * 2, l, mid, ql, qr);
            if (qr > mid)
                ans ^= query(node * 2 + 1, mid + 1, r, ql, qr);

            return ans;
        };
        buildTree(1, 0, n - 1);
        auto pathMask = [&](int u, int v) {
            int mask = 0;
            while (head[u] != head[v]) {
                if (depth[head[u]] < depth[head[v]])
                    swap(u, v);

                mask ^= query(1, 0, n - 1, pos[head[u]], pos[u]);
                u = parent[head[u]];
            }
            if (depth[u] > depth[v])
                swap(u, v);

            mask ^= query(1, 0, n - 1, pos[u], pos[v]);
            return mask;
        };
        vector<bool> ans;
        for (string& q : queries) {
            string type;
            int u, v;
            stringstream ss(q);
            ss >> type >> u;
            if (type == "update") {
                char c;
                ss >> c;
                s[u] = c;
                update(1, 0, n - 1, pos[u], 1 << (c - 'a'));
            } else {
                ss >> v;
                int mask = pathMask(u, v);
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }
        return ans;
    }
};