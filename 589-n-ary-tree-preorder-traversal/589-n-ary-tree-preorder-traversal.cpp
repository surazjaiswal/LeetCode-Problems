/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> ans;
    vector<int> preorder(Node* root) {
        dfs_helper(root);
        return ans;
    }
    
    void dfs_helper(Node *root){
        if(!root)
            return;
        
        ans.push_back(root->val);
        for(auto nbr : root->children)
            dfs_helper(nbr);
        
    }
};