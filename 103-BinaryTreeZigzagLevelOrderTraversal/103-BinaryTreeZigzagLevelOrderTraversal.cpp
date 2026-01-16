// Last updated: 1/16/2026, 8:21:41 PM
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector <vector<int>> res;
        if(root == NULL) return res;
        queue<TreeNode*> ns;
        ns.push(root);
        bool fl = true;
        while(!ns.empty()){
            int s =  ns.size();
            vector<int> row(s);
            for(int i = 0 ; i < s ; i++){
                TreeNode* node = ns.front();
                ns.pop();
                int id = fl? i : s-i-1;
                row[id]= node->val;

                if(node->left){
                    ns.push(node->left);
                }
                if(node->right){
                    ns.push(node->right);
                }
            }
            fl =!fl;
            res.push_back(row);

        }
        return res;
    }
};