class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end());
        int minLen = min(strs[0].size(), strs[n - 1].size());
        string ans = "";
        for (int i = 0; i < minLen; i++) {
            char c = strs[0][i];
            if (c != strs[n - 1][i]) return ans;
            ans += c;
        }
        return ans;
    }
};