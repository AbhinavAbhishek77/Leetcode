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
    TreeNode* addNodeAtDepth(TreeNode* root, int value, int targetDepth) {
        if (targetDepth == 1) {
            TreeNode* newNode = new TreeNode(value);
            newNode->left = root;
            return newNode;
        }
        addNode(root, value, targetDepth);
        return root;
    }

    void addNode(TreeNode* root, int value, int depth) {
        if (depth == 2) {
            TreeNode* leftNode = new TreeNode(value);
            TreeNode* rightNode = new TreeNode(value);
            rightNode->right = root->right;
            leftNode->left = root->left;
            root->right = rightNode;
            root->left = leftNode;
            return;
        }

        if (root->right != nullptr) {
            addNode(root->right, value, depth - 1);
        }
        if (root->left != nullptr) {
            addNode(root->left, value, depth - 1);
        }
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return addNodeAtDepth(root, val, depth);
    }
};