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
        // checking the root value is in required range or not
        return isBST(root,LONG_MIN,LONG_MAX);
    }
    
    bool isBST(TreeNode*root,long min,long max){
        // base case
        if(root == NULL)
            return true;
        
        // rec case
        if(root->val > min && root->val < max){
            bool isLeftBST = isBST(root->left,min,root->val);
            bool isRightBST = isBST(root->right,root->val,max);
            return (isLeftBST && isRightBST);
        }
        else return false;
    }
};