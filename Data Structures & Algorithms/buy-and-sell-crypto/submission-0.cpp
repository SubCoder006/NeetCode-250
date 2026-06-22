class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int bp = prices[0];
        int mp = 0;
        for (int i = 1; i < prices.size(); i++) {
            bp = min(bp, prices[i]);
            mp = max(mp, prices[i] - bp);
        }
        return mp;
    }
};
