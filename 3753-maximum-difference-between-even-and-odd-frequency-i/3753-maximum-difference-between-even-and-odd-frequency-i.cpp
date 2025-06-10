class Solution {
public:
    int maxDifference(string s) {
    vector<int> freq(26, 0);

    // Count frequency of each character
    for (char c : s) {
        freq[c - 'a']++;
    }

    int maxi = 0, mini = INT_MAX;

    for (int f : freq) {
        if (f > 0) {
            if (f % 2 == 0) {
                mini = min(mini, f); // smallest even frequency
            } else {
                maxi = max(maxi, f); // largest odd frequency
            }
        }
    }

    // If no valid even or odd frequency exists
    if (maxi == 0 || mini == INT_MAX) return -1; 

    return maxi - mini;
}
};