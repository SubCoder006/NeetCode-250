class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());

        int maxCnt = 0;

        for(int x : st){ 
            // start of sequence
            if(!st.count(x-1)){
                int curr = x;
                int cnt = 1;

                while(st.count(curr+1)){
                    curr++;
                    cnt++;
                }
                maxCnt = max(maxCnt,cnt);
            }
        }
        return maxCnt;
    }
};
