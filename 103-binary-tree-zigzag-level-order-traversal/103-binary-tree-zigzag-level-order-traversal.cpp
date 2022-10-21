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
    // simple solution with reversing based on some flag
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> nest_res;
        if(root == nullptr){
            return res;   
        }
        bool flag = false;
        queue<TreeNode*> que;
        que.push(root);
        int len = 1;
        while(!que.empty()){
            TreeNode* node = que.front();
            que.pop();
            len--;
            nest_res.push_back(node->val);
            if(node->left != nullptr){
                que.push(node->left);
            }
            if(node->right != nullptr){
                que.push(node->right);
            }
            if(len == 0){
                if(flag){
                    reverse(nest_res.begin(), nest_res.end());
                }
                res.push_back(nest_res);
                flag = !flag;
                len = que.size();
                nest_res.clear();
            }
        }
        return res;
    }
};