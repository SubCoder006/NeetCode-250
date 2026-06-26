class Solution {
   public:
    int jump(vector<int>& nums) {
        int curEnd = 0, farthest = 0, jumps = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            farthest = max(farthest, i + nums[i]);

            if (curEnd == i) {
                jumps++;
                curEnd = farthest;
            }
        }
        return jumps;
    }
};
