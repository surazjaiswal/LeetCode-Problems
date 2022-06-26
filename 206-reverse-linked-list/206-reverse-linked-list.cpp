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
        ListNode *currNode,*prev,*rightNode;
        currNode=head;
        prev=currNode;
        while(currNode!=NULL){
            if(currNode==head){
                prev=currNode;
                rightNode=currNode->next;
                currNode->next=NULL;
                currNode=rightNode;
            }else{
                rightNode=currNode->next;
                currNode->next=prev;
                prev=currNode;
                currNode=rightNode;
            }    
        }
        return prev;
    }
};