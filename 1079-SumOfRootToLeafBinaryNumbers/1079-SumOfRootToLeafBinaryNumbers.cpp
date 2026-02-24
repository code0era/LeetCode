// Last updated: 2/25/2026, 3:03:43 AM
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* node, int cur) {
        if (!node) return 0;

        cur = (cur << 1) | node->val;

        if (!node->left && !node->right) return cur; // leaf

        return dfs(node->left, cur) + dfs(node->right, cur);
    }
};