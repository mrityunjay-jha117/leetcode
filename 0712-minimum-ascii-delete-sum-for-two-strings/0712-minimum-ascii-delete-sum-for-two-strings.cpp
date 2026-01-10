class Solution {
public:
    int dp[1001][1001];
    int func(string& s1, string& s2, int i, int j) {
        if (i == s1.size() && j == s2.size())
            return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if (s1[i] == s2[j])
            return dp[i][j]=func(s1, s2, i + 1, j + 1);
        int a = INT_MAX;
        if (i != s1.size())
            a = int(s1[i]) + func(s1, s2, i + 1, j);
        int b = INT_MAX;
        if (j != s2.size())
            b = int(s2[j]) + func(s1, s2, i, j + 1);
        return dp[i][j]=min(a, b);
    }
    int minimumDeleteSum(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        return func(s1, s2, 0, 0);
    }
};