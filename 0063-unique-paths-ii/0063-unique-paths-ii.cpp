class Solution {
public:
    int n;
    int m;
    int dp[1001][1001];
    int func(vector<vector<int>>& mat, int i, int j) {
        if (j == m - 1 && i == n - 1)
            return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int right = 0;
        if (j + 1 < m && !mat[i][j + 1]) {
            right = func(mat, i, j + 1);
        }
        int bottom = 0;
        if (i + 1 < n && !mat[i + 1][j]) {
            bottom = func(mat, i + 1, j);
        }
        return dp[i][j]=bottom + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();
        memset(dp,-1,sizeof(dp));
        if(mat[n-1][m-1])return 0;
        if(mat[0][0])return 0;
        if (n == 1 && m == 1)
            return !mat[0][0];
        return func(mat, 0, 0);
    }
};