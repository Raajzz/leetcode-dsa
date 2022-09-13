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
    // my version
    
    // void flatten_util(TreeNode* root){
    //     if(root != nullptr){
    //         flatten_util(root->left);
    //         flatten_util(root->right);
    //         if(root->left != nullptr){
    //             TreeNode* temp = root->right;
    //             root->right = root->left;
    //             TreeNode* iter_temp = root->right;
    //             if(iter_temp != nullptr){
    //                 while(iter_temp->right != nullptr){
    //                     iter_temp = iter_temp->right;
    //                 }
    //                 iter_temp->right = temp;   
    //             }
    //         }
    //     }
    // }
    
    void flatten_util(TreeNode* root, TreeNode* &prev){
        if(root == nullptr){
            return;
        }
        flatten_util(root->right, prev);
        flatten_util(root->left, prev);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
    
    void flatten(TreeNode* root){
        TreeNode* prev = nullptr;
        flatten_util(root, prev);   
    }

};  