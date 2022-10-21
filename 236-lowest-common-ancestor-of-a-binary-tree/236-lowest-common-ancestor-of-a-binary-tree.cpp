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
        2. Do a regular DFS (Postorder) traversal (because with postorder traversal we would've
           traversed both left and right part). After doing which if we had both left and right nodes
           then that root is the lowest common ancestor so we return it, but if we had only one either
           left or right, no issue, just return that which is not null, if both are null then return 
           the null, the postorder logic works because of the fact that we have to return null anyway.
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