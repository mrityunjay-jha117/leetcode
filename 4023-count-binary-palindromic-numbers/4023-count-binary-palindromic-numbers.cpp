// class Solution {
// public:
//     string toBinary(long long n) {
//         if (n == 0)
//             return "0";
//         string s = bitset<64>(n).to_string();
//         return s.substr(s.find('1'));
//     }
//     long long ispalindrome(string& a) {
//         long long n = a.size();
//         for (long long i = 0; i < n / 2; i++) {
//             if (a[i] != a[n - i - 1])
//                 return 0;
//         }
//         return 1;
//     }
//     long long func(string& a, long long i, string& temp, bool leading,
//                    bool tight) {
//         if (i == (long long)a.size())
//             return ispalindrome(temp);
//         long long lb = 0;
//         int ub = (tight ? (a[i] - '0') : 1);
//         long long ans = 0;
//         for (long long digit = lb; digit <= ub; digit++) {
//             if (leading && digit == 0)
//                 continue;
//             temp.push_back('0' + digit);
//             ans += func(a, i + 1, temp, false, tight && (digit == ub));
//             temp.pop_back();
//         }
//         return ans;
//     }
//     int countBinaryPalindromes(long long n) {
//         string a = toBinary(n);
//         string temp = "";
//         return func(a, 0, temp, true, true);
//     }
// };

class Solution {
public:
    using ll = long long;

    // Build palindrome string from firstHalf bits string and target total length L
    string buildPalindrome(const string &firstHalf, int L) {
        string res = firstHalf;
        int fhLen = (int)firstHalf.size();
        if (L % 2 == 1) {
            // odd length: skip the middle char when mirroring
            for (int i = fhLen - 2; i >= 0; --i) res.push_back(firstHalf[i]);
        } else {
            // even length: mirror all of firstHalf
            for (int i = fhLen - 1; i >= 0; --i) res.push_back(firstHalf[i]);
        }
        return res;
    }

    int countBinaryPalindromes(long long n) {
        if (n == 0) return 1; // only "0"

        // binary string of n without leading zeros
        string b = bitset<64>(n).to_string();
        b.erase(0, b.find('1'));
        int L = (int)b.size();

        // count = 1 for "0"
        long long count = 1;

        // count all palindromes with length < L
        for (int len = 1; len < L; ++len) {
            int freeBits = (len - 1) / 2; // number of free bits after fixing leading 1
            count += (1LL << freeBits);
        }

        // handle length == L
        int firstHalfLen = (L + 1) / 2; // ceil(L/2)
        string firstHalfStr = b.substr(0, firstHalfLen);
        // minimal first half (leading 1) as integer
        long long minFirstHalf = 1LL << (firstHalfLen - 1);

        // convert firstHalfStr to integer
        long long fhVal = 0;
        for (char c : firstHalfStr) { fhVal = (fhVal << 1) + (c - '0'); }

        // number of smaller first-halves (with leading 1)
        count += (fhVal - minFirstHalf);

        // build palindrome from this firstHalf and check <= n
        string palStr = buildPalindrome(firstHalfStr, L);

        // compare strings (same length), if pal <= b then we can include it
        if (palStr <= b) ++count;

        return (int)count;
    }
};