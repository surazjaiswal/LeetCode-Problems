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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = inorder.size();
        for(int i=0;i<n;i++)
            mp[inorder[i]]=i;
        
        int postIdx = n-1;
        
        TreeNode *root = solve(inorder,postorder,postIdx,0,n-1,n);
        
        return root;        
    }
    
    TreeNode * solve(vector<int> &inorder,vector<int> &postorder,int &postIdx,int in_start,int in_end,int n){
        if(postIdx < 0 || in_start > in_end)
            return NULL;
        
        int num = postorder[postIdx];
        int pos = mp[num];
        
        postIdx--;
        
        TreeNode *node = new TreeNode(num);
        // in postorder right tree is built first then left tree
        node->right = solve(inorder,postorder,postIdx,pos+1,in_end,n);
        node->left = solve(inorder,postorder,postIdx,in_start,pos-1,n);
        
        return node;
    }
};