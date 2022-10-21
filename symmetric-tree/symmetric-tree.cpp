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
    bool isSymmetric(TreeNode* root) {
        deque<TreeNode*> deq;
        deq.push_back(root);
        int len_level = deq.size();
        while(!deq.empty()){
            TreeNode* front = deq.front(); 
            deq.pop_front();
            len_level--;
            if(front != nullptr){
                deq.push_back(front->left);
                deq.push_back(front->right);
            }
            if(len_level == 0){
                for(int i=0; i<deq.size(); i++){
                    if(deq[i] == nullptr){
                        cout << 0 << " ";
                    } else {
                        cout << deq[i]->val << " ";   
                    }
                }
                cout << "\n";
                int deq_size = deq.size() - 1;
                for(int i=0; i<(deq.size()/2); i++){
                    if(deq[i] != nullptr && deq[deq_size - i] != nullptr){
                         if(deq[i]->val != deq[deq_size - i]->val){
                             return false;
                         }
                     } else if(deq[i] != nullptr || deq[deq_size - i] != nullptr){
                         return false;
                     } 
                }
                len_level = deq.size();
            }
        }
        return true;
    }
};