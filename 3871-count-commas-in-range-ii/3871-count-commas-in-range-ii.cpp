class Solution {
    public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long cur = 1000;
        while (cur <= n) {
            ans += n - cur + 1;
            if (cur > 1000000000000000LL) {
                break;
            }
            cur *= 1000;
        }
        return ans;
    }
};