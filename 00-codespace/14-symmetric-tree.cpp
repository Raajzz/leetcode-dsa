// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//         vector<TreeNode*> nodes;
//         if(root == nullptr){
//             return false;
//         }
//         nodes.push_back(nullptr);
//         nodes.push_back(root);
//         int i = 1;
//         int last_idx;
//         while(i < nodes.size()){
//             if(nodes[i] != nullptr){
//                 nodes.push_back((nodes[i]->left != nullptr)?nodes[i]->left:nullptr);
//                 nodes.push_back((nodes[i]->right != nullptr)?nodes[i]->right:nullptr);   
//                 last_idx = i;
//             }
//             i++;
//         }
//         // max index possible or neglecting the null-only row
//         int max_idx = 1;
//         while(max_idx <= last_idx){
//             max_idx *= 2;
//         }
//         int counter_idx = 1;
//         while(counter_idx*2 <= max_idx){
//             int start_ptr = counter_idx;
//             int end_ptr = counter_idx*2 - 1;
//             while(start_ptr < end_ptr){
//                 if(nodes[start_ptr] == nullptr && nodes[end_ptr] == nullptr){
//                     ;
//                 } else if(nodes[start_ptr] != nullptr && nodes[end_ptr] != nullptr){
//                     if(nodes[start_ptr]->val != nodes[end_ptr]->val){
//                         return false;
//                     }
//                 } else {
//                     return false;
//                 }
//                 start_ptr++;
//                 end_ptr--;
//             }
//             counter_idx *= 2;
//         }
//         return true;
//     }
// };

// // wrong solution because
// // [3,4,4,5,null,null,5,6,null,null,6]
// // visualize it and see what happens.

// okay, this is the last time I'm gonna do this, I'm gonna fucking bfs it and if it works, it works, if it isn't, it isn't.

