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
    
    void inorder_trav(TreeNode* root, vector<int> &res){
        if(root != nullptr){
            inorder_trav(root->left, res);
            res.push_back(root->val);
            inorder_trav(root->right, res);
        }
    }
    
    bool isValidBST(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        vector<int> res;
        inorder_trav(root, res);
        int prev = res[0];
        for(int i=1; i<res.size(); i++){
            if(prev >= res[i]){
                return false;
            }
            prev = res[i];
        }
        return true;
    }
};