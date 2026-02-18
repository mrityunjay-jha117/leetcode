class Solution {
public:
    bool hasAlternatingBits(int n) {
        int last=-1;
        while(n){
            int temp=n & 1 ;
            if(temp==last)return false;
            last=temp;
            n=n>>1;
        }
        return true;
    }
};