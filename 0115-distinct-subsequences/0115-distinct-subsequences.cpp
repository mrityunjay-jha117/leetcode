// // recursive solution
// class Solution {
// public:
//     int solve(string &s, string &t, int i, int j) {
//         if(j<0){
//             return 1;
//         }
//         if(i<0){
//             return 0;
//         }
//         if(s[i]==t[j]){
//             return solve(s,t,i-1,j-1)+solve(s,t,i-1,j);
//         }else{
//             return solve(s,t,i-1,j);
//         }
//     }
//     int numDistinct(string s, string t) {
//         int n = s.size();
//         int m = t.size();
//         return solve(s, t, n - 1, m - 1);
//     }
// };
// memoization
// class Solution {
// public:
// vector<vector<int>>dp;
//     int solve(string &s, string &t, int i, int j) {
//         if(j==0){
//             return 1;
//         }
//         if(i==0){
//             return 0;
//         }
//         if(dp[i][j]!=-1)return dp[i][j];
//         if(s[i-1]==t[j-1]){
//             return dp[i][j]=solve(s,t,i-1,j-1)+solve(s,t,i-1,j);
//         }else{
//             return dp[i][j]=solve(s,t,i-1,j);
//         }
//     }
//     int numDistinct(string s, string t) {
//         int n = s.size();
//         int m = t.size();
//         dp=vector<vector<int>>(n+1,vector<int>(m+1,-1));
//         return solve(s, t, n , m );
//     }
// };
// tabulation method
// class Solution {
// public:
// vector<vector<double >>dp;
//     int solve(string &s, string &t) {
//         int n=s.size();
//         int m=t.size();
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 if(s[i-1]==t[j-1]){
//                     dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
//                 }
//                 else{
//                     dp[i][j]=dp[i-1][j];
//                 }
//             }
//         }
//         return (int)dp[n][m];
//     }
//     int numDistinct(string s, string t) {
//         int n = s.size();
//         int m = t.size();
//         dp=vector<vector<double>>(n+1,vector<double >(m+1,0));
//         // by the base case we know the first column is initialized to 1
//         for(int i=0;i<=n;i++){dp[i][0]=1;}
//         return solve(s, t );
//     }
// };
//best tabulated o(n) solution
class Solution {
public:
vector<int>dp;
const int MOD=1e9;
    int solve(string &s, string &t) {
        int n=s.size();
        int m=t.size();
        for(int i=1;i<=n;i++){
            dp[0]=1;
            for(int j=m;j>=1;j--){
                if(s[i-1]==t[j-1]){
                    dp[j]+=dp[j-1];
                    dp[j]%=MOD;
                }
            }
        }
        return (int)dp[m];
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        dp=vector<int>(m+1,0);
        dp[0]=1;
        return solve(s, t);
    }
};