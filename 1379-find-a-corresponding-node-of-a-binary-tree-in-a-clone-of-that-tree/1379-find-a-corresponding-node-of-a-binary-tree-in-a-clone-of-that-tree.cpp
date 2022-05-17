/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode *ans;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        traverse(original,cloned, target);
        return ans;
    }
    
    void traverse(TreeNode* original, TreeNode* cloned, TreeNode* target){
        if(target == original){
            ans = cloned;
            return;
        }
        
        if(original->left)
            getTargetCopy(original->left,cloned->left,target);
        
        if(original->right)
            getTargetCopy(original->right,cloned->right,target);
        
    }
    
};