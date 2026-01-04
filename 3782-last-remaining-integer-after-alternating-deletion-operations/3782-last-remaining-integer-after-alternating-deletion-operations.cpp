class Solution {
public:
    long long lastInteger(long long n) {
        long long first = 1;
        long long gap = 1;
        long long len = n;
        while (len > 1) {
            if(len>1){
                gap*=2;
                len=(len+1)/2;
            }
            if (len > 1) {
                if (len % 2 == 0)
                    first += gap;
                gap *= 2;
                len = (len + 1) / 2;
            }
        }
        return first;
    }
};