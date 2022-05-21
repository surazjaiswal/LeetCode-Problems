/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(!head)
            return head;
        
        unordered_map<Node*,Node*> mp;
        Node *curr =  head;
        Node *ans = new Node(0);
        Node *newHead = ans;
        while(curr){
            Node *newNode = new Node(curr->val);
            mp[curr] = newNode;
            ans->next = newNode;
            ans = ans->next;
            curr = curr->next;
        }
                
        curr = head;
        while(curr){
            if(curr->random){
                Node *newAdd = mp[curr->random];
                mp[curr]->random = newAdd;
            }
            curr = curr->next;
        }

        return newHead->next;
    }
};








