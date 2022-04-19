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
    TreeNode *first=NULL, *second=NULL;
    TreeNode *prev = new TreeNode(INT_MIN);
    void recoverTree(TreeNode* root) {
        inOrder(root);
      
        swap(first->val,second->val);
    }
    
    void inOrder(TreeNode* root){
        if(!root)
            return;
        inOrder(root->left);
        
        if(first == NULL && prev->val > root->val)
            first = prev;
        
        if(first != NULL && prev->val > root->val)
            second = root;
        
        prev = root;
        
        inOrder(root->right);
    }
};