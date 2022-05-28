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
    vector<int> largestValues(TreeNode* root) {
        
        if(!root)
            return  {};
        
        vector<int> ans;
        
        // BFS
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            int max = q.front()->val;
            while(sz--){
                TreeNode *node = q.front();
                q.pop();
                max = (node->val > max)? node->val:max;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            ans.push_back(max);
        }
        return ans;
    }
};