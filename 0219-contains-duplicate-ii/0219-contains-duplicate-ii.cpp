class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        unordered_set<int> mp;
        while (j < n) {
            if (mp.count(nums[j]))
                return true;
            mp.insert(nums[j]);
            if (j - i >= k) {
                mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return false;
    }
};