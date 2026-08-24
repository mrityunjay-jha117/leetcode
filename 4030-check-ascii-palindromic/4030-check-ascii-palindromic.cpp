class Solution {
    public:
        bool isPalindromic(string s) {
                    int n = s.length();
                            int l = 8 * n;
                                    for (int i = 0; i < l / 2; ++i) {
                                                    int j = l - 1 - i;
                                                                if (((s[i / 8] >> (7 - (i % 8))) & 1) != ((s[j / 8] >> (7 - (j % 8))) & 1)) {
                                                                                    return false;
                                                                }
                                    }
                                            return true;
        }
};
