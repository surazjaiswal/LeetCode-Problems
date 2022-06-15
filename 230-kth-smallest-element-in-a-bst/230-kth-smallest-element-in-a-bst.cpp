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
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        return traverse(root,cnt,k);
    }
    
    int traverse(TreeNode *root,int &cnt,int k){
        if(!root)
            return -1;
        
        int L = traverse(root->left,cnt,k);
        if(L != -1)
            return L;
        
        cnt++;
        if(cnt == k)
            return root->val;
        
        return traverse(root->right,cnt,k);
        
        
            
    }
};