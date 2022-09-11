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

//     My Version - Not Working
    
//     int mpsUtilFunction(TreeNode* root, int &maxv){
//        if(root->left == nullptr && root->right == nullptr){
//            maxv = max(maxv, root->val);
//            return root->val;
//        } else {
//            int lh = 0;
//            int rh = 0;
//            maxv = max(maxv, root->val);
//            if(root->left != nullptr){
//                lh = mpsUtilFunction(root->left, maxv);
//                maxv = max(maxv, lh);
//            }
//            if(root->right != nullptr){
//                rh = mpsUtilFunction(root->right, maxv);
//                maxv = max(maxv, rh);
//            }
//            maxv = max(maxv, lh + rh);
//            maxv = max(maxv, root->val + lh + rh);
//            return (lh + rh);
//        }        
//     }

//     int maxPathSum(TreeNode* root) {
//         int maxv = INT_MIN;
//         mpsUtilFunction(root, maxv);
//         return maxv;
//     }
    
    int maxPathSum(TreeNode* root) {
        int maxv = INT_MIN;
        maxPathFinder(root, maxv);
        return maxv;
    }
    
    int maxPathFinder(TreeNode* root, int &maxv){
        if(root == nullptr){
            return 0;
        }
        int lh = max(0, maxPathFinder(root->left, maxv));
        int rh = max(0, maxPathFinder(root->right, maxv));
        maxv = max(maxv, root->val + lh + rh);
        return root->val + max(lh, rh);
    }
    
};