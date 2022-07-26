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
    ListNode* reverseList(ListNode* head) {
        ListNode* three;
        ListNode* two;
        ListNode* one;
        if(head == nullptr){
            return nullptr;
        }
        if (head->next == nullptr){
            return head;
        }
        three = head;
        two = head->next;
        one = head->next->next;
        three->next = nullptr;
        while(one != nullptr){
            two->next = three;
            three = two;
            two = one;
            one = one->next;
        }
        two->next = three;
        return two;
    }
};