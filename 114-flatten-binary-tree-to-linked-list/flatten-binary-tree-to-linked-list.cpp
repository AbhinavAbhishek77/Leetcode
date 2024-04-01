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
    // TC==>O(n)
    // SC==>O(1)

    TreeNode* prev = NULL;
    void solve(TreeNode* root) {
        if (root == NULL)
            return;

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        if (prev != NULL) {
            prev->right = root;
            prev->left = NULL;
        }

        prev = root;
        solve(left);
        solve(right);
    }
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;

        solve(root);
    }
};