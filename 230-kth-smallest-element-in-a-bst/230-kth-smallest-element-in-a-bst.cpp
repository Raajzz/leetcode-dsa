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
    
//     brute forced O(N) time and O(N) space approach - works
//     void getElements(TreeNode* root, vector<int> &elements){
//         if(root != nullptr){
//             getElements(root->left, elements);
//             elements.push_back(root->val);
//             getElements(root->right, elements);
//         }
//     }
    
//     int kthSmallest(TreeNode* root, int k) {
//         vector<int> elements;
//         getElements(root, elements);
//         return elements[k-1];
//     }
    
//     optimal method - O(N) time, usage of an external counter while doing inorder 
//     traversal
    
    void getNumber(TreeNode* root, int pos, int &counter, int &res, bool &isFound){
        if(root != nullptr && !isFound){
            getNumber(root->left, pos, counter, res, isFound);
            if(counter == pos && !isFound){
                isFound = true;
                res = root->val;
                return;
            } else {
                counter++;
            }
            getNumber(root->right, pos, counter, res, isFound);
        }
    }
    
    int kthSmallest(TreeNode* root, int k){
        int res = 0;
        int counter = 1;
        bool isFound = false;
        getNumber(root, k, counter, res, isFound);
        return res;
    }
    
};