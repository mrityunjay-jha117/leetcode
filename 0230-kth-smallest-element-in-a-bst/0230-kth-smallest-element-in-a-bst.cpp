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
    int count = 0;
    int last = 0;
    void func(TreeNode* root) {
        if (count<=0 || !root)
            return;
        func(root->left);
        if (count-->0)
            last = root->val;
        func(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        count = k;
        func(root);
        return last;
    }
};