class Solution {
   public:
    void f(int idx, int n, string s, vector<string>& ds, vector<vector<string>>& ans) {
        if (idx == n) {
            ans.push_back(ds);
            return;
        }
        for (int i = idx; i < n; i++) {
            if (isPalindrome(s, idx, i)) {
                ds.push_back(s.substr(idx, i - idx + 1));
                f(i + 1, n, s, ds, ans);
                ds.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int st, int end) {
        while (st <= end) {
            if (s[st++] != s[end--]) return false;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string> ds;
        vector<vector<string>> ans;
        f(0, n, s, ds, ans);
        return ans;
    }
};
