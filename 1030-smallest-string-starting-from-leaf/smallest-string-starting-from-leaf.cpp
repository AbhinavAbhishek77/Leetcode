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
    string fdfd(TreeNode* root) {
        string result = "";
        fg(root, "", result);
        return result;
    }

    void fg(TreeNode* node, string path, string& result) {
        if (node == NULL)
            return;

        path = char(node->val + 'a') + path;

        if (node->left == NULL && node->right == NULL) {
            if (result.empty() || path < result) {
                result = path;
            }
        }

        fg(node->left, path, result);
        fg(node->right, path, result);
    }

    string smallestFromLeaf(TreeNode* root) { return fdfd(root); }
};