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
int totalActions = 0;

    int redistributeCoins(TreeNode* rootNode) {
        computeExcessCoins(rootNode);
        return totalActions;
    }

    int computeExcessCoins(TreeNode* current) {
        if (current == nullptr) return 0;

        int leftOver = computeExcessCoins(current->left);
        int rightOver = computeExcessCoins(current->right);

        totalActions += abs(leftOver) + abs(rightOver);

        return current->val + leftOver + rightOver - 1;
    }

    int distributeCoins(TreeNode* root) {
        return redistributeCoins(root);
    }
};