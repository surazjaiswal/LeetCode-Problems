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
    unordered_map<int,int> mp;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int preIdx = 0;
        
        for(int i=0;i<n;i++)
            mp[inorder[i]] = i;
        
        TreeNode *root = solve(preorder,inorder,preIdx,0,n-1,n);
        return root;
    }
    
    TreeNode * solve(vector<int> &preorder,vector<int> &inorder,int &preIdx,int in_start,int in_end,int n){
        if(preIdx >= n || in_start > in_end)
            return NULL;
        
        int num = preorder[preIdx];
        int pos = mp[num];
        
        preIdx++;
        
        TreeNode *node = new TreeNode(num);
        node->left = solve(preorder,inorder,preIdx,in_start,pos-1,n);
        node->right = solve(preorder,inorder,preIdx,pos+1,in_end,n);
        return node;
    }
};