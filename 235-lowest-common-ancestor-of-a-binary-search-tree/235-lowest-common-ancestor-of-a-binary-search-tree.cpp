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
    // my version - brute-forced
    
//     void trav(TreeNode* root, TreeNode* checker_node, vector<int> &parents, bool &isFound){
//         if(root != nullptr){
//             if(isFound){
//                 parents.push_back(root->val);
//             } else {
//                 if(root->val == checker_node->val){
//                     isFound = true;
//                     parents.push_back(root->val);
//                     return;
//                 }
//                 trav(root->left, checker_node, parents, isFound);
//                 trav(root->right, checker_node, parents, isFound);
//             }
//         }
//     }
    
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         // store all the parent elements of p after finding the p node
//         // store all the parent elements of q after finding the q node
//         // hash the values of p parent vectors, the let the hash be unordered_map<int, TreeNode*>
//         // check the value, return the first element that occurs.
//         vector<int> p_parent;
//         vector<int> q_parent;
//         bool isFound = false;
//         trav(root, p, p_parent, isFound);
//         trav(root, q, q_parent, isFound);
//         unordered_map<int, TreeNode*> mapper;
//         for(auto val : p_parent){
//             mapper[val] = new TreeNode(val);
//         }
//         for(auto val : q_parent){
//             if(mapper[val] != nullptr){
//                 return mapper[val];
//             }
//         }
//         return nullptr;
//     }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if((p->val > root->val && q->val < root->val) || (p->val < root->val && q->val > root->val) || (p->val == root->val) || (q->val == root->val)){
            return root;
        }
        if(p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        return lowestCommonAncestor(root->left, p, q);
    }
};