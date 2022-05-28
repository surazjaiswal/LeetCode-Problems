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
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        if (!root)
            return {};
        
        vector<int> vt;
        int sum = 0;
        traverse(root, sum, targetSum, vt);
        return ans;
        
    }
    
    void traverse(TreeNode *root, int &sum, int target, vector<int> &vt)
    {
        if (!root)
            return;

        sum += root->val;
        vt.push_back(root->val);
        if (sum == target && (!root->left && !root->right))
            ans.push_back(vt);
        

        traverse(root->left, sum, target, vt);
        traverse(root->right, sum, target, vt);
        vt.pop_back();
        sum -= root->val;
    }
};