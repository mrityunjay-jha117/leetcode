class Solution {
public:
    unordered_set<int> mp = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++) {
            int bits = __builtin_popcount(i);
            if (mp.count(bits))
                ans++;
        }
        return ans;
    }
};