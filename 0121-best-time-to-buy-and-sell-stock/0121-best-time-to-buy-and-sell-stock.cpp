class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>dp(n,prices[0]);
        int ans=0;
        for(int i=1;i<n;i++){
            dp[i]=min(dp[i-1],prices[i]);
            ans=max(ans,prices[i]-dp[i-1]);
        }
        return ans;
    }
};