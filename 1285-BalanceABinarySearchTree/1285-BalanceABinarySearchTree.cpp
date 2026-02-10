// Last updated: 2/11/2026, 12:53:47 AM
#include <vector>
using namespace std;

class Solution {
    vector<TreeNode*> nodes;

    // Step 1: Get sorted nodes via Inorder Traversal
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        nodes.push_back(root);
        inorder(root->right);
    }

    // Step 2: Build balanced tree from sorted array
    TreeNode* build(int start, int end) {
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode* root = nodes[mid];
        root->left = build(start, mid - 1);
        root->right = build(mid + 1, end);
        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        nodes.clear();
        inorder(root);
        return build(0, nodes.size() - 1);
    }
};