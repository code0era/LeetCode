// Last updated: 1/16/2026, 8:21:36 PM
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
int Depth(TreeNode* root) {
        //  recursive way =>> 1+ max(l,r);
        if(root == NULL ) return 0;
        int lh  = Depth(root->left);
        int rh  = Depth(root->right);
        return 1+ max(lh , rh);

    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int l = Depth(root->left);
        int r = Depth(root->right);
        if(abs(l-r)>1)return false;
        bool lf = isBalanced(root->left);
        bool rt = isBalanced(root->right);
        if(!lf || !rt) return false;
        return true;
    }
};

/*
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

class Solution {
public:
    int maxDepth(TreeNode* root) {
        //  recursive way =>> 1+ max(l,r);
        if(root == NULL ) return 0;
        int lh  = maxDepth(root->left);
        int rh  = maxDepth(root->right);
        return 1+ max(lh , rh);

    }
};

 */
