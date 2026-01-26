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
TreeNode* func(vector<int>& arr,int &i,int bound){
    if(i==arr.size() || arr[i]>bound){
        return nullptr;
    }
    TreeNode* curr=new TreeNode(arr[i++]);
    curr->left=func(arr,i,curr->val);
    curr->right=func(arr,i,bound);
    return curr;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return func(preorder,i,INT_MAX);
    }
};