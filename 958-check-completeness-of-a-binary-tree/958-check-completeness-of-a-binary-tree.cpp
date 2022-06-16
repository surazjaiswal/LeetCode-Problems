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
    int countNodes(TreeNode *root){
        if(!root)
            return 0;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    bool isCBT(TreeNode *root,int idx, int size){
        if(!root)
            return true;
        
        if(idx >= size)
            return false;
        
        bool left = isCBT(root->left,idx*2 + 1,size);
        bool right = isCBT(root->right,idx*2 + 2,size);
        
        return (left && right);
    }
    
    bool isCompleteTree(TreeNode* root) {
        int size = countNodes(root);
        return isCBT(root,0,size);
    }
    
    
};