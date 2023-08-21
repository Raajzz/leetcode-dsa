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
    bool hasPathSumRecur(TreeNode* root, int targetSum) {
        if(!root){
            return false;
        }
        
        int newTargetSum = targetSum - root->val;
        
        if(newTargetSum == 0 && !root->right && !root->left){
           return true;
        }
        
        return hasPathSumRecur(root->left, newTargetSum) || hasPathSumRecur(root->right, newTargetSum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum){
        if(!root){
            return false;
        }
        return hasPathSumRecur(root, targetSum);
    }
};