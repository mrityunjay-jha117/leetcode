class Solution {
public:
    long long maximumLength(vector<int>& a) {
        map<int,int> m;
        int one=0;
        for(auto it:a) {
            if(it == 1) one++;
            else m[it]++;
        }

        int ans = max(one, 1);

        for(auto [v, cnt]: m) {
            int tmp = 0;
            long long x = v;

            while(x <= 1e9) {
                if(!m.count(x)) break;
                if(m[x] == 1) {
                    tmp++;
                    break;
                }
                x *= x;
                tmp += 2;
            }

            ans = max(ans, tmp);
        }
        
        if(ans%2 == 0) ans--;
        return ans;
    }
};