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
        
        if(!head->next)
            return NULL;
        
        ListNode *curr = head, *prev=NULL;
        int cnt=1;
        while(curr->next){
            cnt++;
            prev=curr;
            curr = curr->next;
        }
        
        n = cnt - n + 1; // nth form starting
        
        if(cnt == n){
            ListNode *temp = prev->next;
            prev->next = NULL;
            delete(temp);
            
            return head;
        }
        
        if(n==1){
            ListNode *temp = head;
            head = head->next;
            delete(temp);
            return head;
        }
        
        int i=1;
        curr = head;
        ListNode *temp = NULL;
        while(i<n){
            temp=curr;
            curr = curr->next;
            i++;
        }
        temp->next = curr->next;
        delete(curr);
        
        return head;
    }
};