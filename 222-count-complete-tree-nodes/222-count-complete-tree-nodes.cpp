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
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        
        int leftCount=1,rightCount=1;
        TreeNode *leftNode=root->left,*rightNode=root->right;
        while(leftNode){
            leftCount++;
            leftNode = leftNode->left;
        }
        while(rightNode){
            rightCount++;
            rightNode = rightNode->right;
        }
        
        if(leftCount == rightCount){
            int numNodes = pow(2,leftCount) - 1;
            return numNodes;
        }
        
        int leftTraverse = countNodes(root->left);
        int rightTraverse = countNodes(root->right);
        
        return 1 + leftTraverse + rightTraverse;
    }
};