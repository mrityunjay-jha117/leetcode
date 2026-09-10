class Solution {
public:
    int maxSubArraySum(vector<int>& nums) {
        int sum = 0;
        int ans = INT_MIN;
        for (auto num : nums) {
            sum += num;
            ans = max(sum, ans);
            sum = max(0, sum);
        }
        return ans;
    }
    int minSubArraySum(vector<int>& nums) {
        int sum = 0;
        int ans = nums[0];
        for (auto num : nums) {
            sum += num;
            ans = min(sum, ans);
            sum = min(0, sum);
        }
        return ans;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxsub = maxSubArraySum(nums);
        if (maxsub < 0)
            return maxsub;
        return max(maxsub, sum - minSubArraySum(nums));
    }
};