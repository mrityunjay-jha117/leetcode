// optimal solution
class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0)
            return;
        int m = board[0].size();
        if (m == 0)
            return;
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int j = 0; j < m; ++j) {
            if (board[0][j] == 'O' && !vis[0][j]) {
                q.push({0, j});
                vis[0][j] = 1;
                board[0][j] = 'U';
            }
            if (board[n - 1][j] == 'O' && !vis[n - 1][j]) {
                q.push({n - 1, j});
                vis[n - 1][j] = 1;
                board[n - 1][j] = 'U';
            }
        }
        for (int i = 0; i < n; ++i) {
            if (board[i][0] == 'O' && !vis[i][0]) {
                q.push({i, 0});
                vis[i][0] = 1;
                board[i][0] = 'U';
            }
            if (board[i][m - 1] == 'O' && !vis[i][m - 1]) {
                q.push({i, m - 1});
                vis[i][m - 1] = 1;
                board[i][m - 1] = 'U';
            }
        }
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            vis[x][y] = 1;
            for (auto& it : dir) {
                int na = x + it[0];
                int nb = y + it[1];
                if (na >= 0 && nb >= 0 && na < n && nb < m &&
                    vis[na][nb] == 0 && board[na][nb] == 'O') {
                    board[na][nb] = 'U';
                    vis[na][nb] = 1;
                    q.push({na, nb});
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == 'U') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
// class Solution {
// public:
//     // doing brute force
//     vector<vector<int>> dir = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
//     void solve(vector<vector<char>>& board) {
//         int n = board.size();
//         int m = board[0].size();
//         queue<pair<int, int>> q;
//         vector<vector<int>> vis(n, vector<int>(m, 0));
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (board[i][j] == 'O' && vis[i][j] == 0) {
//                     vis[i][j] = 1;
//                     q.push({i, j});
//                     bool flag = false;
//                     vector<vector<int>>mp;
//                     mp.push_back({i,j});
//                     if (i == 0 || j == 0 || i == n-1 || j == m-1)
//                         flag = true;
//                     while (!q.empty()) {
//                         int a = q.front().first;
//                         int b = q.front().second;
//                         q.pop();
//                         for (auto& it : dir) {
//                             int na = a + it[0];
//                             int nb = b + it[1];
//                             if (na >= 0 && na < n && nb >= 0 &&
//                                 nb < m && vis[na][nb] == 0 &&
//                                 board[na][nb]=='O') {
//                                     if(na==n-1 || nb==m-1 || na==0 ||
//                                     nb==0){//bpundary pe hai
//                                             flag=true;
//                                     }
//                                     vis[na][nb]=1;
//                                     mp.push_back({na,nb});
//                                     q.push({na,nb});
//                             }
//                         }
//                     }
//                     if (!flag) {
//                         for (auto& it : mp)
//                             board[it[0]][it[1]] = 'X';
//                     }
//                 }
//             }
//         }
//     }
// };
