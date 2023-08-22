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
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val == val){
            head = head->next;
        }
        
        ListNode* newHead = new ListNode(0);
        ListNode* returnNode = head;
        newHead->next = head;
        
        while(head){
            if(head->val != val){
                newHead = newHead->next;
            } else {
                newHead->next = newHead->next->next;
            }
            head = head->next;
        }
        return returnNode;
    }
};