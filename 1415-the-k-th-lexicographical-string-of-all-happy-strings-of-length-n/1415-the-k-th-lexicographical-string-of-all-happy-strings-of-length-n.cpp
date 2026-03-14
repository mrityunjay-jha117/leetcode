class Solution {
public:
    string ans = "";

    void func(int k, char prev, int sz) {
        if (sz == 1) return;

        char n1 = 'z', n2 = 'z';

        for (char i = 'a'; i <= 'c'; i++) {
            if (i == prev) continue;
            if (n1 == 'z') n1 = i;
            else n2 = i;
        }

        int half = sz >> 1;

        if (k <= half) {
            ans.push_back(n1);
            func(k, n1, half);
        } 
        else {
            ans.push_back(n2);
            func(k - half, n2, half);
        }
    }

    string getHappyString(int n, int k) {

        int blockSize = 1 << (n - 1);

        int block = ceil(k * 1.0 / blockSize);

        if (block > 3) return "";

        k = k - (block - 1) * blockSize;

        char prev = (block == 1) ? 'a' : (block == 2) ? 'b' : 'c';

        ans = prev;

        func(k, prev, blockSize);

        return ans;
    }
};