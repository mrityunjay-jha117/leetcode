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
    // my solution
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        map<int, TreeNode*> mp;
        TreeNode* root = new TreeNode(preorder[0]);
        mp[preorder[0]] = root;
        int n = preorder.size();
        for (int i = 1; i < n; i++) {
            TreeNode* temp = new TreeNode(preorder[i]);
            if (preorder[i - 1] > preorder[i]) {
                mp[preorder[i - 1]]->left = temp;
            } else {
                auto node = (--mp.lower_bound(preorder[i]))->second;
                node->right = temp;
            }
            mp[preorder[i]] = temp;
        }
        return root;
    }
};