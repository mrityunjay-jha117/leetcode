class Solution {
public:
    // approach 1
    int minimumDeletions(string s) {
        int ans = INT_MAX;
        int n = s.size();
        vector<int> b(n, 0);
        int b_count = 0;
        for (int i = 0; i < n; i++) {
            b[i] = b_count;
            if (s[i] == 'b') 
                b_count++;            
        }
        vector<int> a(n, 0);
        int a_count=0;
        for (int i = n-1; i >=0 ; i--) {
            a[i] = a_count;
            if (s[i] == 'a') 
                a_count++;            
        }
        for(int i=0;i<n;i++){
            ans=min(ans,a[i]+b[i]);
        }
        return ans;
    }
};