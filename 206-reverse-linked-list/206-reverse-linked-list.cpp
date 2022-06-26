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
    ListNode* reverseList(ListNode* root) {
        if(!root)
            return root;
        
        ListNode *temp = reverseList(root->next);
        
        if(!temp)
            return root;
        
        ListNode *curr = root;
        while(curr->next){
            curr = curr->next;
        }
        
        root->next = NULL;
        curr->next = root;
        
        return temp;
    }
};