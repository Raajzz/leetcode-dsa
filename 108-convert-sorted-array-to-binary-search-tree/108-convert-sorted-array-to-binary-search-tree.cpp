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
    void tree_creator(TreeNode* &root, int low, int high, vector<int> &nums){
        if(low > high){
            root = nullptr;
        } else {
            int mid = low + (high - low)/2;
            root = new TreeNode(nums[mid]);
            tree_creator(root->left, low, mid-1, nums);
            tree_creator(root->right, mid+1, high, nums);
        }
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = nullptr;
        int low = 0;
        int high = nums.size() - 1;
        tree_creator(root, low, high, nums);
        return root;
    }
};