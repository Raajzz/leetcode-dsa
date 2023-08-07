/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* newHead = new ListNode(INT_MIN);
        newHead->next = head;
        ListNode* parentPtr = newHead;
        ListNode* ptr = head;
        while(ptr){
            bool flag = false;
            while(ptr->next && ptr->val == ptr->next->val){
                ptr->next = ptr->next->next;
                flag = true;
            }
            if(flag){
                parentPtr->next = ptr->next;
                ptr = ptr->next;
            } else {
                parentPtr = ptr;
                ptr = ptr->next;
            }
        }
        return newHead->next;
    }
};