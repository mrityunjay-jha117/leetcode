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
    int ans = 0;
    void func(TreeNode* root, int temp) {
        if (!root->left && !root->right) {
            int newtemp = (temp << 1) | root->val;
            ans += newtemp;
            return;
        }
        // for the left child
        if (root->left) {
            int newtemp = (temp << 1) | root->val;
            func(root->left, newtemp);
        }
        // for the right child
        if (root->right) {
            int newtemp = (temp << 1) | root->val;
            func(root->right, newtemp);
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        func(root, 0);
        return ans;
    }
};