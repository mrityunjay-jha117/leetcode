class Solution {
public:
    int dp[1001][1001];
    bool func(string& s, int i, int j) {
        if (i >= j)
            return true;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == s[j])
            return dp[i][j] = func(s, i + 1, j - 1);
        return dp[i][j] = false;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int index = INT_MAX;
        int len = 0;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (func(s, i, j)) {
                    if (len < j - i + 1) {
                        len = j - i + 1;
                        index = i;
                    }
                }
            }
        }
        return s.substr(index, len);
    }
};