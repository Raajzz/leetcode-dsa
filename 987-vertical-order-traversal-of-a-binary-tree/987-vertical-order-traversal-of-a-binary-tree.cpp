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
    void trav(TreeNode* root, map<int, map<int, multiset<int>>> &mapper, int vlevel, int hlevel){
        if(root != nullptr){
            mapper[vlevel][hlevel].insert(root->val);
            trav(root->left, mapper, vlevel-1, hlevel+1);
            trav(root->right, mapper, vlevel+1, hlevel+1);   
        }
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mapper;
        int vlevel = 0;
        int hlevel = 0;
        trav(root, mapper, vlevel, hlevel);
        vector<vector<int>> res;
        for(auto vlevel_val : mapper){
            vector<int> nest_vec;
            for(auto hlevel_val : vlevel_val.second){
                for(auto node_val:hlevel_val.second){
                    nest_vec.push_back(node_val);
                }
            }
            res.push_back(nest_vec);
        }
        return res;
    }
};