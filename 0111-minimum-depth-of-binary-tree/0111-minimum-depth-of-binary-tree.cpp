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
    int minDepthRecur(TreeNode* root) {
        if(!root){
            return 1e9;
        }
        if(!root->left && !root->right){
            return 1;
        }
        int left = minDepthRecur(root->left);
        int right = minDepthRecur(root->right);
        return 1 + min(left, right);
    }
    int minDepth(TreeNode* root){
        if(!root){
            return 0;
        }
        return minDepthRecur(root);
    }
};