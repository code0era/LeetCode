// Last updated: 3/10/2026, 10:25:37 PM
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        if(root->left == nullptr) return 1 + minDepth(root->right);
        if(root->right == nullptr) return 1 + minDepth(root->left);

        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};