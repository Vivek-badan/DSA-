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

    TreeNode* solve(vector<int>& preorder,
                    int& index, long long bound) {

        // Base case 1: All elements processed
        if (index == preorder.size()) {
            return nullptr;
        }

        // Base case 2: Value exceeds allowed bound
        if (preorder[index] > bound) {
            return nullptr;
        }

        // Create current node
        TreeNode* root = new TreeNode(preorder[index]);

        index++;

        // Construct left subtree
        root->left = solve(preorder, index, root->val);

        // Construct right subtree
        root->right = solve(preorder, index, bound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        int index = 0;

        return solve(preorder, index, LLONG_MAX);
    }
};
