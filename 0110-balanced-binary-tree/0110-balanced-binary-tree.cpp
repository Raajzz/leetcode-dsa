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
    int checkHeightBalance(TreeNode* root, bool &balanceFlag){
        if(root == nullptr){
            return 0;
        }
        int leftHeight = checkHeightBalance(root->left, balanceFlag);
        int rightHeight = checkHeightBalance(root->right, balanceFlag);
        if(abs(leftHeight - rightHeight) > 1){
            balanceFlag = false;
        }
        return 1 + max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        bool balanceFlag = true;
        checkHeightBalance(root, balanceFlag);
        return balanceFlag;
    }
};