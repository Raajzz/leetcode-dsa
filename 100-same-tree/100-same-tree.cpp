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
    
    // simple recursive implementation
    void trav(TreeNode* p, TreeNode* q, bool &res){
        if(p != nullptr ^ q != nullptr){
            res = false;
            return;
        }
        if(p != nullptr){
            if(p->val != q->val){
                res = false;
                return;
            }
            trav(p->left, q->left, res);
            trav(p->right, q->right, res);
        }
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool res = true;
        trav(p, q, res);
        return res;
    }
};