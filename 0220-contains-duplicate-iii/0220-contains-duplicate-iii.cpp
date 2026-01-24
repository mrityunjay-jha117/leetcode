class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        if (indexDiff <= 0 || valueDiff < 0) return false;

        set<long long> s;  

        for (int i = 0; i < nums.size(); i++) {
            long long x = nums[i];
            auto it = s.lower_bound(x - valueDiff);
            if (it != s.end() && *it <= x + valueDiff) {
                return true;
            }
            s.insert(x);
            if (i >= indexDiff) {
                s.erase(nums[i - indexDiff]);
            }
        }

        return false;
    }
};