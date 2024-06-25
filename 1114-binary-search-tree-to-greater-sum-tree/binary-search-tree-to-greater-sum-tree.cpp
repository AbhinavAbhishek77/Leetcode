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
    int xx = 0;

    TreeNode* solve(TreeNode* root) {
        if (root->right != NULL)
            solve(root->right);

        xx = root->val = xx + root->val;

        if (root->left != NULL)
            solve(root->left);

        return root;
    }
    TreeNode* bstToGst(TreeNode* root) { return solve(root); }
};