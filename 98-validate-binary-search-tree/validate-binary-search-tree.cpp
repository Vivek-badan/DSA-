
class Solution {
public:
    bool solve(TreeNode* root,
               long long low,
               long long high) {

        // Base case
        if (root == nullptr) {
            return true;
        }

        // Check whether current node violates BST range
        if (root->val <= low || root->val >= high) {
            return false;
        }

        // Check left subtree
        bool left = true;

        if (root->left != nullptr) {
            left = solve(root->left, low, root->val);
        }

        // Check right subtree
        bool right = true;

        if (root->right != nullptr) {
            right = solve(root->right, root->val, high);
        }

        // Both subtrees must be valid
        return left && right;
    }

    bool isValidBST(TreeNode* root) {

        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};
