class Solution {
public:
    double a = 0;
    double dp[200][200];
    double func(int i, int j) {

        if (j < 0 || j > i)
            return 0;

        if (i == 0)
            return a ;

        if (dp[i][j] != -2.0)
            return dp[i][j];
        double left = max(0.0, func(i - 1, j - 1) - 1.0) / 2.0;
        double right = max(0.0, func(i - 1, j) - 1.0) / 2.0;
        return dp[i][j] = left+right;
    }

    double champagneTower(int poured, int query_row, int query_glass) {

        a = poured;

        // dp initialize with -2.0 (because answer can be -1 also)
        for (int i = 0; i < 200; i++)
            for (int j = 0; j < 200; j++)
                dp[i][j] = -2.0;

        return min(1.00, func(query_row, query_glass));
    }
};
