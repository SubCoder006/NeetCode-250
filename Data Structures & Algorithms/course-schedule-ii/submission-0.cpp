class Solution {
   public:
    vector<int> findOrder(int n, vector<vector<int>>& edge) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n), ans(n);
        for (auto& e : edge) {
            adj[e[1]].push_back(e[0]);
            indeg[e[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        int count = 0;
        while (!q.empty()) {
            int u = q.front();
            ans.push_back(u);
            count++;
            q.pop();

            for (auto v : adj[u]) {
                indeg[v]--;
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }
        if(count == n) return ans;
        return {};
    }
};
