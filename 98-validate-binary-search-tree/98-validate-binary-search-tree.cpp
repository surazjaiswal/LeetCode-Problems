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
    bool isValidBST(TreeNode* root) {
        // root node ranges from (-inf,+inf)
        // leftSubtree will range from (-inf,root->val]
        // rightSubtree will range from [root->val,+inf)
        // doing this recusievly
        
        return solve(root,LONG_MIN,LONG_MAX);
    }
    
    bool solve(TreeNode *root, long min,long max){
        if(!root)
            return true;
        
        if(root->val > min && root->val < max){
            int left = solve(root->left,min,root->val);
            int right = solve(root->right,root->val,max);
            return (left && right);
        }
        
        return false;
    }
};