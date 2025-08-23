class Solution {
public:
    int dp[10][2][(1<<10)][2];
    int func(string &a, int ind, bool tight, int mask, bool leading) {
        if(ind == a.size()) return leading ? 0 : 1; // valid only if at least one digit chosen
        if(dp[ind][tight][mask][leading]!=-1)return dp[ind][tight][mask][leading];
        int lb = 0;
        int ub = tight ? (a[ind] - '0') : 9;
        int res = 0;
        
        for(int digit = lb; digit <= ub; digit++) {
            if((mask & (1<<digit)) && !leading) continue; // digit already used
            
            bool next_tight = tight && (digit == ub);
            bool next_leading = leading && (digit == 0);
            
            int next_mask = mask;
            if(!next_leading) next_mask |= (1<<digit); // only mark digit if not leading zero
            
            res += func(a, ind+1, next_tight, next_mask, next_leading);
        }
        return dp[ind][tight][mask][leading]=res;
    }

    int numDupDigitsAtMostN(int n) {
        string a = to_string(n);
        memset(dp,-1,sizeof(dp));
        return n - func(a, 0, true, 0, true);
    }
};
