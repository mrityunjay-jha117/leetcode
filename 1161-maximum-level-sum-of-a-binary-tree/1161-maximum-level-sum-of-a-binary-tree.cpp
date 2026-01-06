/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int ans = INT_MIN;
    int g_sum=INT_MIN;
    int func(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level=1;
        while (!q.empty()) {
            int n=q.size();
            int sum=0;
            while(n--){
                auto temp=q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            if(sum>g_sum){
                g_sum=sum;
                ans=level;
            }
            level++;
        }
        return ans;
    }
    int maxLevelSum(TreeNode* root) {
        return func(root);
    }
};