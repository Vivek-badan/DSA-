/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void encode(TreeNode* root, string &ans){
        if(root == NULL){
            ans += "N,";
            return;
        }

        ans += to_string(root->val) + ",";

        encode(root->left, ans);
        encode(root->right, ans);
    }

    TreeNode* decode(stringstream &ss){
        string val;

        getline(ss, val, ',');

        if(val == "N")
            return NULL;

        TreeNode* root = new TreeNode(stoi(val));

        root->left = decode(ss);
        root->right = decode(ss);

        return root;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";

        encode(root, ans);

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);

        return decode(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));