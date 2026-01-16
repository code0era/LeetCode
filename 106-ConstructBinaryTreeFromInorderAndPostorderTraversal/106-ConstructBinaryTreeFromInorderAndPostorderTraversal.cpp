// Last updated: 1/16/2026, 8:21:37 PM
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

    unordered_map<int, int> mp;
    int postId;
    TreeNode* solve(vector<int>&postorder , vector<int> &inorder, int start , int end){
        if(start > end) return NULL;
         int rootV = postorder[postId--];
         TreeNode* root = new TreeNode(rootV);

         int mid   = mp[rootV];

         root->right = solve(postorder , inorder, mid+1, end);
         root->left = solve(postorder , inorder, start , mid-1);

        return root;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        postId = postorder.size()-1;
        for(int i = 0 ; i < inorder.size(); i++){
            mp[inorder[i]] = i ;
        }
         return solve(postorder , inorder, 0 , inorder.size()-1);

    }
};