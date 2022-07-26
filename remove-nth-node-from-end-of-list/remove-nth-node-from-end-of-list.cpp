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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // two pass method
        ListNode* ptr_1 = head;
        ListNode* ptr_2 = head;
        int counter = 1;
        if(head == nullptr || head->next == nullptr){
            return nullptr;
        }
        while(ptr_1 != nullptr && ptr_1->next != nullptr){
            ptr_1 = ptr_1->next->next;
            counter += 2;
        }
        if(ptr_1 == nullptr){
            counter--;
        }
        int pos = counter + 1 - n;
        int new_counter = 1;
        if(pos == 1){
            head = head->next;
            return head;
        }
        while( new_counter + 1 != pos ){
            ptr_2 = ptr_2->next;
            new_counter++;
        }
        ptr_2->next = ptr_2->next->next;
        // cout << counter << "\n" << pos << "\n" << new_counter << "\n";
        return head;
    }
};