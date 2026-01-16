// Last updated: 1/16/2026, 8:21:44 PM
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
    bool isM(TreeNode* t1 ,TreeNode* t2){
        if(!t2 && !t1) return true;
        if(!t2 || !t1) return false;
        return (t1->val == t2->val) &&  isM(t1->left , t2->right) && isM(t1->right , t2->left);
    }    
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isM(root->left, root->right);
    }
};