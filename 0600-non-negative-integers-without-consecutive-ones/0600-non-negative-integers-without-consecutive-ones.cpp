class Solution {
public:
    int dp[40][2][3];
    int func(string& a, int ind, bool tight, int prev) {
        if (ind == a.size())return 1;
        if(dp[ind][tight][prev]!=-1)return dp[ind][tight][prev];
        int lb = 0;
        int ub = (tight) ? (a[ind] - '0') : 1;
        int ans = 0;
        for (int digit = lb; digit <= ub; digit++) {
            if (prev == 1 && prev == digit)
                continue;
            ans += func(a, ind + 1, (tight && (digit == ub)) ? true : false,
                        digit);
        }
        return dp[ind][tight][prev]=ans;
    }
    int findIntegers(int n) {
        string binary = bitset<32>(n).to_string();
        binary.erase(0, binary.find_first_not_of('0'));
        memset(dp,-1,sizeof(dp));
        return func(binary, 0, true, 2);
    }
};