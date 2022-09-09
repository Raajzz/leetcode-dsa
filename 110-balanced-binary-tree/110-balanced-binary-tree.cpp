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
    
    int maxDepth(TreeNode* root, bool &res) {
        if(root == nullptr){
            return 0;
        }
        int lh = maxDepth(root->left, res);
        int rh = maxDepth(root->right, res);
        if(res && (abs(lh-rh)>1)){
            res = false;
        }
        return 1 + max(lh, rh);
    }
    
    bool isBalanced(TreeNode* root) {
        bool res = true;
        maxDepth(root, res);
        return res;
    }
};