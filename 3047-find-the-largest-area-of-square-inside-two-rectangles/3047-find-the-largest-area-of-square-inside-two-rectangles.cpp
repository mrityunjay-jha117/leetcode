class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& a,
                                vector<vector<int>>& b) {
        int n = a.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int x1 = a[i][0];
            int y1 = a[i][1];
            int x2 = b[i][0];
            int y2 = b[i][1];

            for (int j = i + 1; j < n; j++) {
                int x1b = a[j][0];
                int y1b = a[j][1];
                int x2b = b[j][0];
                int y2b = b[j][1];

                // overlap width
                int overlapW = min(x2, x2b) - max(x1, x1b);
                // overlap height
                int overlapH = min(y2, y2b) - max(y1, y1b);

                if (overlapW > 0 && overlapH > 0) {
                    long long side = min(overlapW, overlapH);
                    ans = max(ans, side * side);
                }
            }
        }
        return ans;
    }
};
