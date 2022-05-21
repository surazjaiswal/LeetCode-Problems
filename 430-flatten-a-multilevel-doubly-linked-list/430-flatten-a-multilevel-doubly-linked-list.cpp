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
        
        if (!head)
            return head;

        Node *curr = head;
        while (curr)
        {
            if (curr->child)
            {
                Node *nextHolder = curr->next;
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;
                while (curr->next)
                {
                    curr = curr->next;
                }
                if (nextHolder!=NULL)
                {
                    curr->next = nextHolder;
                    curr->next->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};