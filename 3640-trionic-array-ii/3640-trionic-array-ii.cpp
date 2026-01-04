class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        int start = -1;
        long long ans = LLONG_MIN;
        // getting all the descending
        int ind = 1;
        while (ind < n) {
            if (nums[ind - 1] > nums[ind]) {
                if (start == -1)
                    start = ind - 1;
                sum += nums[ind - 1];
            } else {
                if (start != -1) {
                    sum += nums[ind - 1];
                    int end = ind - 1;
                    // logic of the expansion
                    // increasing backward
                    if (start - 1 >= 0 && nums[start - 1] < nums[start]) {
                        int i = start - 1;
                        sum += nums[i];
                        while (i > 0 && nums[i - 1] < nums[i] &&
                               nums[i - 1] > 0) {
                            sum += nums[i - 1];
                            i--;
                        }
                        // increasing forward
                        if (end + 1 < n && nums[end] < nums[end + 1]) {
                            int j = end + 1;
                            sum += nums[j];
                            while (j + 1 < n && nums[j] < nums[j + 1]) {
                                ans = max(sum, ans);
                                sum += nums[j + 1];
                                j++;
                            }
                            ans = max(sum, ans);
                        }
                    }
                }
                        start = -1;
                        sum = 0;
                    }
                    ind++;
                }
                return ans;
            }
        };