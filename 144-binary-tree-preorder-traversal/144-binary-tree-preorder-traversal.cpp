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

    void helper_function(TreeNode* root, vector<int> &res_vec){
        if(root != nullptr){
            res_vec.push_back(root->val);
            helper_function(root->left, res_vec);
            helper_function(root->right, res_vec);
        }
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res_vec;
        helper_function(root, res_vec);
        return res_vec;
    }
};