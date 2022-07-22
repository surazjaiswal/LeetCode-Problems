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
        ListNode *listA, *listB, *tempA, *tempB;
        listA = new ListNode(-1);
        listB = new ListNode(-1);
        
        tempA = listA, tempB = listB;
        
        ListNode *curr = head;
        while(curr){
            if(curr->val < x){
                tempA->next = new ListNode(curr->val);
                tempA = tempA->next;
            }
            else{
                tempB->next = new ListNode(curr->val);
                tempB = tempB->next;
            }
            curr = curr->next;
        }
        
        tempA->next = listB->next;
        
        return listA->next;
    }
};