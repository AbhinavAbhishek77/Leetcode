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
    vector<int> o;

    TreeNode* solve(TreeNode* r) {
        solve1(r);
        return b(0, o.size() - 1);
    }

    void solve1(TreeNode* r) {
        if (r == nullptr)
            return;
        solve1(r->left);
        o.push_back(r->val);
        solve1(r->right);
    }

    TreeNode* b(int l, int h) {
        if (l > h)
            return nullptr;
        int m = (l + h) / 2;
        TreeNode* r = new TreeNode(o[m]);
        r->left = b(l, m - 1);
        r->right = b(m + 1, h);
        return r;
    }
    TreeNode* balanceBST(TreeNode* root) { return solve(root); }
};