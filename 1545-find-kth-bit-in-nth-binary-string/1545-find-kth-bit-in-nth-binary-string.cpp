class Solution {
public:
    string func(int n) {
        string ans = "0";
        for (int i = 2; i <= n; i++) {
            string prev = ans;
            // invert
            for (int j = 0; j < ans.size(); j++)
                ans[j] = (ans[j] == '0') ? '1' : '0';
            // reversed
            reverse(ans.begin(), ans.end());
            ans = prev + "1" + ans;
        }
        return ans;
    }
    char findKthBit(int n, int k) { return func(n)[k - 1]; }
};