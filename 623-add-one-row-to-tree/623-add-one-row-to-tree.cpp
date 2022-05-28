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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root)
            return root;
        
        if(depth == 1){
            TreeNode *newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        traverse(root,val,depth,1);
        return root;
        
    }
    
    
    void traverse(TreeNode *root,int val, int depth,int cnt){
        if(!root)
            return;
        
        if(cnt == depth - 1){
            TreeNode *newNode, *leftNode, *rightNode;
            leftNode = root->left, rightNode = root->right;
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            root->left->left = leftNode;
            root->right->right = rightNode;
        }
        
        traverse(root->left,val,depth,cnt+1);
        traverse(root->right,val,depth,cnt+1);
    }
    
};