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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int returnFlag = 0;
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        int carry = 0;
        ListNode* lastPtr = nullptr;
        while(ptr1 && ptr2){
          int sum = ptr1->val + ptr2->val + carry;
          ptr1->val = sum % 10;
          ptr2->val = sum % 10;
          lastPtr = ptr2;
          carry = sum / 10;
          ptr1 = ptr1->next;
          ptr2 = ptr2->next;
        }
        while (ptr1){
          int sum = ptr1->val + carry;
          ptr1->val = sum % 10;
          carry = sum / 10;
          lastPtr = ptr1;
          ptr1 = ptr1->next;
          returnFlag = 1;
        } 
        while(ptr2){
          int sum = ptr2->val + carry;
          ptr2->val = sum % 10;
          carry = sum / 10;
          lastPtr = ptr2;
          ptr2 = ptr2->next;
          returnFlag = 2;
        }
        if(carry == 1 && lastPtr){
          lastPtr->next = new ListNode(1);
        }
        if(returnFlag == 1){
          return l1;
        }
        return l2;
    }
};