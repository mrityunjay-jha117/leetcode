/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
        bool ans=true;
    bool isBalanced(TreeNode* root) {
        func(root);
        return ans;
    }
    int func(TreeNode* root) {
        if(!root)return 0;
        int left=(root->left)?func(root->left):0;
        int right=(root->right)?func(root->right):0;
        if(abs(right-left)>1)ans=false;
        return max(right,left)+1;
    }
};