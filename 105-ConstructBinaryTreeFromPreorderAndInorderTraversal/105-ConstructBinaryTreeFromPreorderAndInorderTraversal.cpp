// Last updated: 1/16/2026, 8:21:38 PM
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
    unordered_map<int, int> mp;
    int preIndex = 0;
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start,
                    int end) {
        if (start > end) {
            return NULL;
        }

        int rootV = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootV);

        int mid  = mp[rootV];

        root ->left= solve(preorder, inorder  ,start , mid-1);
        root ->right= solve(preorder, inorder  ,mid+1 , end);
        return root ;
    }




    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return solve(preorder, inorder, 0, inorder.size() - 1);
    }
};