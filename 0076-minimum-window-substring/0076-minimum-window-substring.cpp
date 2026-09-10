class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int i = 0;
        int j = 0;
        unordered_map<int, int> mp;
        for (auto ch : t)
            mp[ch]++;
        int count = 0;
        int minlen = INT_MAX;
        int starti = -1;
        while (j < n) {
            if (mp[s[j]] > 0)
                count++;
            mp[s[j]]--;
            j++;
            while (m == count) {
                if (j - i < minlen) {
                    minlen = j - i;
                    starti = i;
                }
                mp[s[i]]++;
                if (mp[s[i]] > 0) {
                    count--;
                }
                i++;
            }
        }
        return starti == -1 ? "" : s.substr(starti, minlen);
    }
};