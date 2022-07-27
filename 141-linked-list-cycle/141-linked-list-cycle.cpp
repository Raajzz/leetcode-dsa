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
    bool hasCycle(ListNode *head) {
        if(head == nullptr){
            return false;
        }
        ListNode* fp = head->next;
        ListNode* sp = head;
        while(fp != nullptr && fp->next != nullptr){
            if(fp == sp){
                return true;
            }
            fp = fp->next->next;
            sp = sp->next;
        }
        return false;
    }
};