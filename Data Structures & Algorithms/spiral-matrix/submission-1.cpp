class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> ans;

        int l = 0, b = n - 1, t = 0, r = m - 1;
        while (l <= r && t <= b) {
            // left to right
            for (int i = l; i <= r; i++) {
                ans.push_back(mat[t][i]);
            }
            t++;
            // top to bottom
            for (int i = t; i <= b; i++) {
                ans.push_back(mat[i][r]);
            }
            r--;
            // right to left
            if (t <= b) {
                for (int i = r; i >= l; i--) {
                    ans.push_back(mat[b][i]);
                }
                b--;
            }
            // bottom to top
            if (l <= r) {
                for (int i = b; i >= t; i--) {
                    ans.push_back(mat[i][l]);
                }
                l++;
            }
        }
        return ans;
    }
};
