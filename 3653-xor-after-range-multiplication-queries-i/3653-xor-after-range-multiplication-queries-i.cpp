#include <vector>
using namespace std;
class Solution {
    public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long long mod = 1000000007;
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            long long v = q[3];
            for (int idx = l; idx <= r; idx += k) {
                nums[idx] = (nums[idx] * v) % mod;
            }
        }
        int ans = 0;
        for (int x : nums) {
            ans ^=x;
        }
            return ans;
    }
    };