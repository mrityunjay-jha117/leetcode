class Solution {
public:
    bool isAnagram(string s, string t) {
        int dp[26] = {0};
        for (auto ch : s)
            dp[ch - 'a']++;
        for (auto ch : t)
            dp[ch - 'a']--;
        for (auto ch : dp) {
            if (ch)
                return false;
        }
        return true;
    }
};