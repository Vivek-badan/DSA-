class Solution {
public:
    int ans = 0;

    pair<int, int> solve(TreeNode* root) {
        if (root == NULL) {
            return {0, 0};
        }

        // Get sum and count from left subtree
        
        pair<int, int> left = solve(root->left);

        // Get sum and count from right subtree
        pair<int, int> right = solve(root->right);

        // Current subtree sum
        int totalSum = left.first + right.first + root->val;

        // Current subtree node count
        int totalCount = left.second + right.second + 1;

        // Check average
        if (totalSum / totalCount == root->val) {
            ans++;
        }

        // Return sum and count to parent
        return {totalSum, totalCount};
    }

    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};