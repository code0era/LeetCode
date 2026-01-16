// Last updated: 1/16/2026, 8:20:53 PM
class Solution {
public:
    // Step 1: Mark parent of each node
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Store parents
        unordered_map<TreeNode*, TreeNode*> parent;
        markParent(root, parent);

        // BFS from target
        unordered_set<TreeNode*> vis;
        queue<TreeNode*> q;

        q.push(target);
        vis.insert(target);

        int dist = 0;

        while (!q.empty()) {
            int s = q.size();
            if (dist == k) break;

            dist++;

            for (int i = 0; i < s; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Left child
                if (node->left && !vis.count(node->left)) {
                    vis.insert(node->left);
                    q.push(node->left);
                }

                // Right child
                if (node->right && !vis.count(node->right)) {
                    vis.insert(node->right);
                    q.push(node->right);
                }

                // Parent
                if (parent[node] && !vis.count(parent[node])) {
                    vis.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
        }

        // Collect result
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};
