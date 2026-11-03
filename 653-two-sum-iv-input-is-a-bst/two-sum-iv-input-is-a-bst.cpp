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

   bool solve(TreeNode*root,int k , unordered_set<int>&st){
    //base case
    if(root==nullptr) return 0;

    int complement= k - (root->val);

    if(st.find(complement)!=st.end()) return true;

    st.insert(root->val);
    bool left=false;
    if(root->left!=nullptr){
        left=solve(root->left,k,st);
    }
    bool right=false;
    if(root->right!=nullptr){
        right=solve(root->right,k,st);
     }

    return (right||left);
    
   }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int>st;
        return solve(root,k,st);
    }
};