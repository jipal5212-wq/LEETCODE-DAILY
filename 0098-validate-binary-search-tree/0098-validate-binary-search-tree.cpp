/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode* root, TreeNode* checkLeft, TreeNode* checkRight) {
        if (root == NULL) return true;

        if (checkLeft != NULL && root->val <= checkLeft->val)
            return false;

        if (checkRight != NULL && root->val >= checkRight->val)
            return false;

        return helper(root->left, checkLeft, root) &&
               helper(root->right, root, checkRight);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
};