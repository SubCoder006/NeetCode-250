class Solution {
   public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& edges,
                                     vector<vector<int>>& queries) {
        vector<int> indeg(n, 0);
        vector<vector<bool>> pre(n, vector<bool>(n, false));
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            indeg[v]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto v : adj[u]) {
                pre[v][u] = true;

                for (int k = 0; k < n; k++) {
                    if (pre[u][k]) {
                        pre[v][k] = true;
                    }
                }
                indeg[v]--;
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }
        vector<bool> ans;
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            ans.push_back(pre[v][u]);
        }

        return ans;
    }
};