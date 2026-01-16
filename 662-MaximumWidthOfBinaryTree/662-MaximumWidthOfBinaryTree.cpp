// Last updated: 1/16/2026, 8:20:59 PM
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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0 ;

        }
        int ans = 0 ; 
        queue<pair<TreeNode* , long long>> q ;
        q.push({root , 0});
        while(!q.empty()){
            int s = q.size();
            int  f =  q.front().second;
            int  l =  q.back().second;
            ans  = max(ans , l-f+1);
             for(int i = 0 ; i < s ; i++){
                auto it = q.front();
                q.pop();
                TreeNode* node = it.first;
                 long long idx = it.second  - f ;

                if(node->left)q.push({node->left , 2*idx +1});
                if(node->right)q.push({node->right , 2*idx +2});
             }
        }
        return ans;
    }
};
