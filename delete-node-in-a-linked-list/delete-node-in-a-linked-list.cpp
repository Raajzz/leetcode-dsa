/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* ptr_1 = node;
        ListNode* ptr_2 = node->next;
        ptr_1->val = ptr_2->val;
        ptr_1->next = ptr_2->next;
        delete ptr_2;
    }
};