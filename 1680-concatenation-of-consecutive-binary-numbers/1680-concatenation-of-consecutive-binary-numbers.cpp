class Solution {
    int mod = 1e9 + 7;

public:
    int concatenatedBinary(int n) {
        long long num = 0;
        for (int i = 1; i <= n; i++) {
            int temp = 32 - __builtin_clz(i);
            num = ((num << temp) | i) % mod;
        }
        return num;
    }
};