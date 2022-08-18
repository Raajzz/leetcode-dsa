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

// static int max_val = 0;

class Solution {
public:    
    void trav_fn(TreeNode* root, int len_counter, int &max_val){
        if(root != nullptr){
            if(root->left == nullptr && root->right == nullptr){
                if(len_counter > max_val){
                    max_val = len_counter;
                }
            }
            trav_fn(root->left, len_counter+1, max_val);
            trav_fn(root->right, len_counter+1, max_val);
        }
    }
    
    int maxDepth(TreeNode* root) {
        int max_val = 0;
        trav_fn(root, 1, max_val);
        return max_val;
    }
};