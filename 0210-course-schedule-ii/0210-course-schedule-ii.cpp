class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);
        for (auto& it : prerequisites) {
            adj[it[0]].push_back(it[1]);
            indeg[it[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for (auto& it : adj[node]) {
                if (!(--indeg[it]))
                    q.push(it);
            }
        }
        for (auto& it : indeg)
            if (it)
                return {};
        reverse(ans.begin(),ans.end());
        return ans;
    }
};