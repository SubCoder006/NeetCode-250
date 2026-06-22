class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> us;

        for (int i = 0; i < n; i++) {
            if (us.count(nums[i])) return true;
            us.insert(nums[i]);
            if (i >= k) us.erase(nums[i - k]);
        }
        return false;
    }
};