class Solution {
public:
    //   i
    // 2,1,1,5,6,2,3,1
    // 1 1 1 2 3
    vector<int> func(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (nums[j] < nums[i] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        return dp;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> rev = nums;
        reverse(rev.begin(), rev.end());
        vector<int> a = func(nums);
        vector<int> b = func(rev);
        reverse(b.begin(), b.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if(a[i]>1 && b[i]>1)
            ans = max(ans, a[i] + b[i]-1);
        }
        return n-ans;
    }
};