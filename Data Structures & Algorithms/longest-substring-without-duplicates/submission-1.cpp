class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n = s.size();

        int maxLen = 0, stIdx = 0;
        for (int i = 0; i < n; i++) {
            if (mp.find(s[i]) != mp.end()) {
                if(stIdx < mp[s[i]] + 1)
                    stIdx = mp[s[i]] + 1;
            }
            maxLen = max(maxLen, i - stIdx + 1);
            mp[s[i]] = i;
        }
        return maxLen;
    }
};
