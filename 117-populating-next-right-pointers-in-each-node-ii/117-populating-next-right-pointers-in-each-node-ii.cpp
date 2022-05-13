/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        // to check if root is NULL
        if(!root)
            return root;
        
        
        // Using BFS Traversal
        // queues to queue TreeNodes
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int n=q.size(); // size of current level
            Node *temp;
            for(int i=0;i<n;i++){
                temp = q.front();
                q.pop();
                if(i!=n-1) // check for the last node
                    temp->next = q.front(); // populating next nodes
                if(temp->left) 
                    q.push(temp->left); // adding node to queue
                if(temp->right)
                    q.push(temp->right); // adding node to queue
            }
        }
        return root;
    }
};