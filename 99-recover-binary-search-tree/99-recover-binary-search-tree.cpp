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
    vector<int> nums;
    void recoverTree(TreeNode* root) {
        inOrder(root);
        sort(nums.begin(),nums.end());

        TreeNode *first=NULL,*second=NULL;
        int i=0;
        for(auto it : vt){
            if(it->val == nums[i++])
                continue;
            if(first)
                second = it;
            else
                first = it;
        }
        
        swap(first->val,second->val);
    }
    
    void inOrder(TreeNode* root){
        if(!root)
            return;
        inOrder(root->left);
        vt.push_back(root);
        nums.push_back(root->val);
        inOrder(root->right);
    }
};