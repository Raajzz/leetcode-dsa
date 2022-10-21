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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        if(root == nullptr){
            return vec;
        }
        queue<TreeNode*> que;
        que.push(root);
        int level_len = 1;
        vector<int> new_vec;
        while(!que.empty()){
            TreeNode* front = que.front();
            que.pop();
            new_vec.push_back(front->val);
            if(front->left){
                que.push(front->left);
            }
            if(front->right){
                que.push(front->right);
            }
            level_len--;
            if(level_len == 0){
                vec.push_back(new_vec);
                new_vec = {};
                level_len = que.size();
            }
        }
        return vec;
    }
};