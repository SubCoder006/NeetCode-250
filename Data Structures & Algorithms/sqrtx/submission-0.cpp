class Solution {
   public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        int low = 0, high = x, ans = 0;
        while (low <= high) {
            int mid = (high - low) / 2 + low;
            if ((long long)mid * mid == x) {
                return mid;
            } else if ((long long)mid * mid < x) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};