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
    int cp(TreeNode* r, int d) {
        int c = 0;
        dfs(r, d, c);
        return c;
    }

    vector<int> dfs(TreeNode* n, int d, int& c) {
        if (!n)
            return {};

        if (isLeaf(n))
            return {1};

        vector<int> ld = dfs(n->left, d, c);
        vector<int> rd = dfs(n->right, d, c);

        solve1(ld, rd, d, c);

        return cd(ld, rd, d);
    }

    bool isLeaf(TreeNode* n) { return !n->left && !n->right; }

    void solve1(vector<int>& ld, vector<int>& rd, int d, int& c) {
        for (int l : ld) {
            for (int r : rd) {
                if (l + r <= d) {
                    c++;
                }
            }
        }
    }

    vector<int> cd(vector<int>& ld, const vector<int>& rd, int d) {
        vector<int> res;
        for (int l : ld) {
            if (l + 1 < d)
                res.push_back(l + 1);
        }
        for (int r : rd) {
            if (r + 1 < d)
                res.push_back(r + 1);
        }
        return res;
    }

    int countPairs(TreeNode* root, int distance) { return cp(root, distance); }
};