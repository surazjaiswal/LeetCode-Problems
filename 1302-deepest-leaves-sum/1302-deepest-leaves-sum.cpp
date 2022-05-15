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
    int deepestLeavesSum(TreeNode* root) {
        int h = getHeight(root);
        
        queue<TreeNode*> q;
        q.push(root);
        int i=1,sum=0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                TreeNode *node = q.front();
                q.pop();
                if(i == h)
                    sum += node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            i++;
        }
        return sum;
    }
    
    int getHeight(TreeNode *root){
        if(!root)
            return 0;
        
        int leftH = getHeight(root->left);
        int rightH = getHeight(root->right);
        
        return max(leftH,rightH) + 1;
    }
    
};