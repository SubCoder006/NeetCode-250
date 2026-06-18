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
    int countComponents(int n, vector<vector<int>>& edges) {
        dsu d(n);
        int components = n;
        for (auto& e : edges) {
            if (d.unite(e[0], e[1])) {
                components--;
            }
        }
        return components;
    }
};
