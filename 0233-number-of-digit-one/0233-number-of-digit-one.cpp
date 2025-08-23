class Solution {
public:
    // dp making formula
    // dp[i] represents the number of 1 upto the i digit largest number
    // for example dp[3] represents the
    // the total number of digit 1 appearing in all non-negative integers less
    // than or equal to 999.
    vector<long long int> dp;

    long long int func(long long int n, string& a, long long int idx) {
        long long int pd = a[n - idx] - '0';
        if (idx == 0) {
            return (pd >= 1) ? 1 : 0;
        }
        long long int res = 0;
        if (pd > 1) {
            res = pd * dp[idx] + pow(10, idx) + func(n, a, idx - 1);
        } else {
            long long int s = stoi(a.substr(n - idx + 1));
            if(pd==0)s=-1;
            res = pd * dp[idx] + (s + 1LL) + func(n, a, idx - 1);
        }
        return res;
    }
    int countDigitOne(int n) {
        string a = to_string(n);
        long long int m = a.size() - 1;
        dp=vector<long long int>(10,0);
        dp[1] = 1;
        for (long long int i = 2; i <= 9; i++) {
            dp[i] = 10 * dp[i - 1] + pow(10, i - 1);
        }
        return func(m, a, m);
    }
};