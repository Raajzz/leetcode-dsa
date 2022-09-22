/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val; 
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        /*
        1. Brute Forced
            - Find all the ancestors of p
            - Find all the ancestors of q
            - Find the exact position where the two arrays diverage, that position - 1 will be 
            our lowest common ancestor
            - Time complexity is O(N) + O(N) + O(N)
            - Space Complexity is O(N) + O(N)
        2. 
        */
        
        if(root == nullptr){
            return nullptr;
        }
        if(root == p || root == q){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left && right){
            return root;
        }
        if(left){
            return left;
        }
        return right;
    }
}; 