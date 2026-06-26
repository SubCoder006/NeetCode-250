class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        int i = 0;
        while (i < n) {
            if (i > maxi) return false;
            maxi = max(maxi, i + nums[i]);
            if (maxi >= n - 1) return true;
            i++;
        }
        return false;
    }
};
