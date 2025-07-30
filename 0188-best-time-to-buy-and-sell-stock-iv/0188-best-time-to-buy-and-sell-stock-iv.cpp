class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& prices,int k) {
        int n=prices.size();
        if (n == 0 || k==0)
            return 0;
        for (int i = n-1; i >= 0; i--) {
            for (int j = 2 * k - 1; j >= 0; j--) {
                if (j % 2 == 0) {
                    dp[i][j] = max(-prices[i] + dp[i + 1][j + 1], dp[i + 1][j]);
                } else {
                    dp[i][j] = max(prices[i] + dp[i + 1][j + 1], dp[i + 1][j]);
                }
            }
        }
        return dp[0][0];
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        dp = vector<vector<int>>(n + 1, vector<int>(2 * k + 1, 0));
        return solve(prices, k);
    }
};