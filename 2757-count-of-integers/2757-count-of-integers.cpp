class Solution {
public:
    static const long long MOD = 1000000007LL;
    // dp[pos][tight][sum][leading]
    long long dp[25][2][401][2];
    int minS, maxS;
    string s;

    long long dfs(int pos, bool tight, int sum, bool leading) {
        if (sum > maxS) return 0; // prune
        if (pos == (int)s.size()) {
            // if we've built a number and its digit sum in range -> count it
            return (sum >= minS && sum <= maxS) ? 1 : 0;
        }
        long long &memo = dp[pos][tight][sum][leading];
        if (memo != -1) return memo;
        memo = 0;
        int ub = tight ? (s[pos] - '0') : 9;
        for (int d = 0; d <= ub; ++d) {
            bool nleading = leading && (d == 0);
            bool ntight = tight && (d == ub);
            memo += dfs(pos + 1, ntight, sum + d, nleading);
            if (memo >= MOD) memo -= MOD;
        }
        return memo;
    }

    // subtract 1 from numeric string (returns "0" if result < 0)
    string decOne(string a) {
        int n = a.size();
        int i = n - 1;
        while (i >= 0 && a[i] == '0') { a[i] = '9'; --i; }
        if (i < 0) return "0";
        a[i] -= 1;
        // remove leading zeros? keep same length is fine for DP but we can strip for efficiency
        size_t pos = a.find_first_not_of('0');
        if (pos == string::npos) return "0";
        return a.substr(pos);
    }

    long long countUpTo(string x) {
        if (x == "0") return 0; // numbers from 0..0 with min_sum>=1 produce 0
        s = x;
        // pad not necessary; dfs handles various lengths; but keep s as is
        memset(dp, -1, sizeof(dp));
        return dfs(0, true, 0, true) % MOD;
    }

    int count(string num1, string num2, int min_sum, int max_sum) {
        minS = min_sum;
        maxS = max_sum;
        string prev = decOne(num1);
        long long a = countUpTo(num2);
        long long b = countUpTo(prev);
        long long ans = (a - b) % MOD;
        if (ans < 0) ans += MOD;
        return (int)ans;
    }
};