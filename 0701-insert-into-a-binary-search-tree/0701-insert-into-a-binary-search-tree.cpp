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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)return new TreeNode(val);
        TreeNode* temp = root;
        while (temp) {
            if (!temp->left && !temp->right) {
                if (temp->val > val) {
                    temp->left = new TreeNode(val);
                    break;
                } else {
                    temp->right = new TreeNode(val);
                    break;
                }
            }
            if (temp->val < val) {
                if (!temp->right) {
                    temp->right = new TreeNode(val);
                    break;
                }
                temp = temp->right;
            } else {
                if (!temp->left) {
                    temp->left = new TreeNode(val);
                    break;
                }
                temp = temp->left;
            }
        }
        return root;
    }
};