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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root=NULL;
        for(int num : preorder){
            if(root==NULL){
                root = new TreeNode(num);
            }
            else{
                TreeNode *temp = root,*prev;
                while(temp!=NULL){
                    prev = temp;
                    if(num > temp->val)
                        temp=temp->right;
                    else
                        temp=temp->left;
                }
                if(num < prev->val)
                    prev->left = new TreeNode(num);
                else
                    prev->right = new TreeNode(num);
            }
        }
        return root;
    }
};