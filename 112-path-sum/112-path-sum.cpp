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
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        return getSum(root,sum,targetSum);
    }
    bool getSum(TreeNode *node,int sum,int targetSum){
        
        if(!node)
            return false;
        
        sum+=node->val;
        if(sum==targetSum && !node->left && !node->right)
            return true; 
        
        if(sum==targetSum && (!node->left || !node->right))
            return false;
        
        bool leftSum = getSum(node->left,sum,targetSum);
        bool rightSum = getSum(node->right,sum,targetSum);
        
        // sum-=node->val;
        
        return leftSum || rightSum;
    }
};