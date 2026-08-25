#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        long long cur_profit = 0;
        for (int i = 0; i < n; ++i) {
            cur_profit += (long long)strategy[i] * prices[i];
        }
        int h = k / 2;
        long long delta = 0;
        for (int j = 0; j < h; ++j) {
            delta += -(long long)strategy[j] * prices[j];
        }
        for (int j = h; j < k; ++j) {
            delta += (long long)(1 - strategy[j]) * prices[j];
        }
        long long max_delta = delta;
        for (int i = 1; i <= n - k; ++i) {
            delta = delta + (long long)strategy[i - 1] * prices[i - 1]
            - prices[i + h - 1]
            + (long long)(1 - strategy[i + k - 1]) * prices[i + k - 1];
            max_delta = max(max_delta, delta);
        }
        return cur_profit + max(0LL, max_delta);
    }
};