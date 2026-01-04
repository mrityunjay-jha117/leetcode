class Solution {
public:
    long long total(long long n) {
        return n * (n + 1) / 2;
    }

    long long func(vector<int>& order, int time, string s) {
        int n = s.size();

        for (int i = 0; i <= time; i++) {
            s[order[i]] = '*';
        }

        long long ans = 0;
        long long count = 0;

        for (char c : s) {
            if (c != '*') {
                count++;
            } else {
                ans += total(count);
                count = 0;
            }
        }
        ans += total(count);

        return total(n) - ans;
    }

    int minTime(string s, vector<int>& order, int k) {
        int n = order.size();
        int low = 0, high = n - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long test = func(order, mid, s);

            if (test >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
