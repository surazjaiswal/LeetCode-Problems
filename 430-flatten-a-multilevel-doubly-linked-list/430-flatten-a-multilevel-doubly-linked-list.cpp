/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL)
            return head;
        
        Node *node = head;
        while(node!=NULL){
            if(node->child!=NULL){
                Node *next = node->next;
                node->next = flatten(node->child);
                node->next->prev = node;
                node->child = NULL;
                while(node->next!=NULL){
                    node = node->next;
                }
                if(next!=NULL){
                    node->next = next;
                    node->next->prev = node;
                }
            }
            node = node->next;
            
        }
        return head;
    }
};