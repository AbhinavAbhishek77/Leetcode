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
    int diffmini = INT_MAX;
    void solveInorder(TreeNode* root) {
        if (root == NULL)
            return;

        solveInorder(root->left);

        if (prev != NULL) {
            diffmini = min(diffmini, root->val - prev->val);
        }
        prev = root;
        solveInorder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        solveInorder(root);
        return diffmini;
    }
};