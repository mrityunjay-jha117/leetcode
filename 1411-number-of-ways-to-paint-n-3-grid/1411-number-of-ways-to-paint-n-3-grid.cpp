class Solution {
public:
    const long long mod = 1e9 + 7;
    int dp[4][4][4][5001];
    int func(int a, int b, int c, int n) {
        if (n == 0)
            return 1;
        if (dp[a][b][c][n] != -1)
            return dp[a][b][c][n];
        int curra = -1;
        int currb = -1;
        int currc = -1;
        int ans = 0;
        for (int i = 0; i < 3; i++) {
            if (a == i)
                continue;
            curra = i;
            for (int j = 0; j < 3; j++) {
                if (b == j || curra == j)
                    continue;
                currb = j;
                for (int k = 0; k < 3; k++) {
                    if (c == k || currb == k)
                        continue;
                    currc = k;
                    ans += func(curra, currb, currc, n - 1);
                    ans %= mod;
                }
            }
        }
        return dp[a][b][c][n] = ans;
    }
    int numOfWays(int n) {
        memset(dp, -1, sizeof(dp));
        return func(3, 3, 3, n);
    }
};