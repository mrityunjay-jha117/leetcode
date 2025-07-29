class Solution {
public:
    // lcs banao
    string lcs(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] =1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
                }
            }
        }
        // printing the lcs
        int i = n;
        int j = m;
        string ans = "";
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                ans += str1[i - 1];
                i--;
                j--;
            } else {
                if (dp[i][j - 1] > dp[i - 1][j]) {
                    j--;
                } else {
                    i--;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
  string shortestCommonSupersequence(string str1, string str2) {
        string common = lcs(str1, str2);
        string res = "";
        int i = 0, j = 0;
        for (char c : common) {
            while (i < str1.size() && str1[i] != c) res += str1[i++];
            while (j < str2.size() && str2[j] != c) res += str2[j++];
            res += c;
            i++, j++;
        }
        res += str1.substr(i) + str2.substr(j);
        return res;
    }

};