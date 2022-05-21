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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode *oddNode=head, *evenNode=head->next, *evenHead=head->next;
        while(evenNode && evenNode->next){
            oddNode->next = oddNode->next->next;
            evenNode->next = evenNode->next->next;
            oddNode = oddNode->next;
            evenNode = evenNode->next;
        }
        
        oddNode->next = evenHead;
        return head;
    }
};