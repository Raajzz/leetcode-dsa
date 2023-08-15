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
    ListNode* partition(ListNode* head, int x) {
        // This can be created by using two dummy lists (right and left) and finally combining the two lists
        ListNode* left = new ListNode(0);
        ListNode* right = new ListNode(0);
        ListNode* leftStart = left;
        ListNode* rightStart = right;

        ListNode* currNode = head;

        while(currNode){
            if(currNode -> val < x){
                left->next = currNode;
                currNode = currNode->next;
                left = left->next;
                left->next = nullptr;
            } else {
                right->next = currNode;
                currNode = currNode->next;
                right = right->next;
                right->next = nullptr;
            }
        }
        if(!left){
            return rightStart->next;
        }
        left->next = rightStart->next;;

        return leftStart->next;
    }
};