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
    void solve(TreeNode* root, vector<int>& ans) {

        // Base case
        if (root == NULL) {
            return;
        }

        // Step 1: Traverse left subtree
        solve(root->left,ans);


        // Step 2: Store current node value
        ans.push_back(root->val);


        // Step 3: Traverse right subtree
        solve(root->right,ans);

    }

    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;

        solve(root, ans);

        return ans;
    }
};
