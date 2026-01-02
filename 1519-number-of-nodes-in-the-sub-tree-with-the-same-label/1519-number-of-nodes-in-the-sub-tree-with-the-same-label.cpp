class Solution {
public:
    vector<int> ans;

    void addFunc(array<int,26>& A, const array<int,26>& B) {
        for (int i = 0; i < 26; i++) {
            A[i] += B[i];
        }
    }

    array<int,26> func(vector<vector<int>>& adj,
                       string& labels,
                       int root,
                       int parent) {

        array<int,26> sum{};
        sum.fill(0);

        for (int it : adj[root]) {
            if (it == parent) continue;
            auto child = func(adj, labels, it, root);
            addFunc(sum, child);
        }

        ans[root] = ++sum[labels[root] - 'a'];
        return sum;
    }

    vector<int> countSubTrees(int n,
                              vector<vector<int>>& edges,
                              string labels) {

        vector<vector<int>> adj(n);
        for (auto& it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        ans.resize(n);
        func(adj, labels, 0, -1);
        return ans;
    }
};
