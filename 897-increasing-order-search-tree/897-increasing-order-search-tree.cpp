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
    vector<TreeNode*> vt;
    TreeNode* increasingBST(TreeNode* root) {
        
        inOrder(root);
        int i;
        for(i=1;i<vt.size();i++){
            vt[i-1]->right = vt[i];
            vt[i-1]->left = NULL;
        }
        vt[i-1]->right=NULL;
        vt[i-1]->left=NULL;
        
        return vt[0];
    }
    
    void inOrder(TreeNode *root){
        
        if(!root)
            return;
        
        inOrder(root->left);
        vt.push_back(root);
        inOrder(root->right);
        
    }
};