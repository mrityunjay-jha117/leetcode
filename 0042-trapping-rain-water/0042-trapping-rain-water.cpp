class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pref = height;
        vector<int> suff = height;
        for (int i = 1; i < n; i++)
            pref[i] = max(pref[i], pref[i - 1]);
        for (int i = n - 2; i > 0; i--)
            suff[i] = max(suff[i], suff[i + 1]);
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            ans += min(pref[i], suff[i]) - height[i];
        }
        return ans;
    }
};