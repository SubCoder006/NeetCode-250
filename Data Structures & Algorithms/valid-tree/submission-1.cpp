class Solution {
   public:
    struct dsu {
        vector<int> parent, size;
        dsu(int n) {
            parent.resize(n);
            size.resize(n, 1);
            iota(parent.begin(), parent.end(), 0);
        }
        int find(int u) {
            if (u == parent[u]) return u;
            return parent[u] = find(parent[u]);
        }
        bool unite(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) return false;
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];

            return true;
        }
    };
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        dsu d(n);
        int components = n;
        for (auto& it : edges) {
            if (d.unite(it[0], it[1])) {
                components--;
            } else {
                return false;
            }
        }
        return components == 1;
    }
};
