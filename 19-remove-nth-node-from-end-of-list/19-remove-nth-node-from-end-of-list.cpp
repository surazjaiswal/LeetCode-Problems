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
        ListNode *p1,*p2;
        p1=head;
        p2=head;
        int cnt=1;
        while(p1->next!=NULL){
            p1=p1->next;
            cnt++;
        }
        
        if (cnt==1)
            return NULL;
        
        if(cnt==n){
            head=p2->next;
            return head;
        }
        
        int c=1;
        while(c < cnt-n){
            p2=p2->next;
            c++;
        }
        if(p2->next!=NULL){
            p2->next = p2->next->next;
            return head;
        }
        p2->next = p2->next;
        return head;
    }
};