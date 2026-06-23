class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (auto& str : strs) {
            vector<int> freq(26, 0);
            for (char c : str) freq[c - 'a']++;

            // build key
            string key = "";
            for (int i = 0; i < 26; i++) {
                key += "#";
                key += to_string(freq[i]);
            }
            mp[key].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto& v : mp) {
            ans.push_back(v.second);
        }
        return ans;
    }
};
