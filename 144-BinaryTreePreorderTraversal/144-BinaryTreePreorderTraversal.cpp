// Last updated: 1/16/2026, 8:21:26 PM
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;
       if( root ==NULL) return res;
       stack<TreeNode*> st;
       st.push(root);
       while(!st.empty()){
            TreeNode* root = st.top();
            st.pop();
            res.push_back(root->val);
            if(root->right!=NULL) st.push(root->right);
            if(root->left!=NULL) st.push(root->left);
            }
       
        return res;
    }
};