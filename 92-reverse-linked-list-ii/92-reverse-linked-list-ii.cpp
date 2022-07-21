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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right)
            return head;
        
        vector<int> vt;
        int cnt = 0;
        ListNode *curr = head;
        while(cnt<right && curr){
            cnt++;
            if(cnt >= left){
                vt.push_back(curr->val);
            }
            curr = curr->next;
        }
        
        reverse(vt.begin(),vt.end());
        
        int k=0;
        cnt=0;
        
        curr = head;
        while(cnt<right && curr){
            cnt++;
            if(cnt >= left){
                curr->val= vt[k++];
            }
            curr = curr->next;
        }
        
        return head;
    }
};