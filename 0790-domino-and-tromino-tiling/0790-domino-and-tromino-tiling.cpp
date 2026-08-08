class Solution {
public:
const int mod=1e9+7;
    int numTilings(int n) {
        long dp[n+1];
        if(n<=3){
            if(n==1)return 1;
            else if(n==2)return 2;
            else return 5;
        }
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        for(int i=4;i<=n;i++){

            dp[i]=2*dp[i-1]+dp[i-3];
            dp[i]=dp[i]%mod;
        }
        return dp[n];
    }
};