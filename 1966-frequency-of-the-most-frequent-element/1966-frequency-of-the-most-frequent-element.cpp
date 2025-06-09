#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long windowSum = 0;
        int l = 0, ans = 1;

        for (int r = 0; r < n; ++r) {
            windowSum += nums[r];

            // cost to raise everything in [l..r] to nums[r] is:
            //   nums[r] * windowSize - windowSum
            while ((long long)nums[r] * (r - l + 1) - windowSum > k) {
                windowSum -= nums[l++];
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
