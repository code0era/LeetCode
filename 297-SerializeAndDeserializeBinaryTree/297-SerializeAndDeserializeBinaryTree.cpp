// Last updated: 1/16/2026, 8:21:07 PM
class Codec {
public:
    // Helper for serialization (Preorder)
    void shelp(TreeNode* root, string &s) {
        if (!root) {
            s += "#,";
            return;
        }
        s += to_string(root->val) + ",";
        shelp(root->left, s);
        shelp(root->right, s);
    }

    // Encodes a tree to a single string
    string serialize(TreeNode* root) {
        string ss;
        shelp(root, ss);
        return ss;
    }

    // Helper for deserialization
    TreeNode* dhelp(queue<string> &q) {
        string val = q.front();
        q.pop();

        if (val == "#") return NULL;

        TreeNode* root = new TreeNode(stoi(val));
        root->left = dhelp(q);
        root->right = dhelp(q);

        return root;
    }

    // Decodes your encoded data to tree
    TreeNode* deserialize(string data) {
        queue<string> q;
        string temp = "";

        for (char c : data) {
            if (c == ',') {
                q.push(temp);
                temp = "";
            } else {
                temp += c;
            }
        }

        return dhelp(q);
    }
};
