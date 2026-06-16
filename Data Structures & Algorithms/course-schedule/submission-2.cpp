class Solution {
   public:
    bool canFinish(int n, vector<vector<int>>& edge) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n);
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
            q.pop();
            count++;

            for (auto v : adj[u]) {
                indeg[v]--;
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }
        return count == n;
    }
};
