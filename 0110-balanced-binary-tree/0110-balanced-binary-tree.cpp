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
    int checkHeightBalance(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int leftHeight = checkHeightBalance(root->left);
        if(leftHeight == -1){
            return -1;
        }
        int rightHeight = checkHeightBalance(root->right);
        if(rightHeight == -1){
            return -1;
        }
        if(abs(leftHeight - rightHeight) > 1){
            return -1;
        }
        return 1 + max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        if(checkHeightBalance(root) == -1){
            return false;
        };
        return true;
    }
};