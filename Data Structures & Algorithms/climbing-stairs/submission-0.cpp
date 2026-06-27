class Solution {
   public:
    int climbStairs(int n) {
        if (n == 1 || n == 2) return n;
        int dp1 = 1, dp2 = 2;
        for (int i = 2; i < n; i++) {
            int ans = dp1 + dp2;
            dp1 = dp2;
            dp2 = ans;
        }
        return dp2;
    }
};
