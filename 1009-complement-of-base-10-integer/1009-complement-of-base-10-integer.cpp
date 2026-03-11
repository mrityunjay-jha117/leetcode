class Solution {
public:
    int bitwiseComplement(int n) {
        int m=1;
        while(m<n){
            m=(m<<1)+1;
        }
        return n^m;
    }
};