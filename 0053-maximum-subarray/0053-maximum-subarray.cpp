class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int ans = -1e8;
        for (auto num : nums) {
            sum += num;
            ans = max(ans, sum);
            sum = max(sum, 0);
        }
        return ans;
    }
};