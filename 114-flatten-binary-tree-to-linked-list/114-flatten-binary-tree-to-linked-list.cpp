/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        
        if(!root)
            return;
        
        vector<TreeNode*> nodes;
        traverse(root,nodes);
        
        TreeNode *temp = root;
        temp->left = NULL;
        for(int i=1;i<nodes.size();i++){
            TreeNode *node = new TreeNode(nodes[i]->val);
            temp->right = node;
            temp->left = NULL;
            temp = temp->right;
        }
        temp->right = NULL;
    }
    
    void traverse(TreeNode *root,vector<TreeNode*> &nodes){
        if(!root)
            return;
        
        nodes.push_back(root);
        traverse(root->left,nodes);
        traverse(root->right,nodes);
    }
};