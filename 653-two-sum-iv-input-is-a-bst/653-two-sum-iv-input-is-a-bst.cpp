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
    set<int> st;
    bool findTarget(TreeNode* root, int k) {
        return find(root,k);
    }
    bool find(TreeNode* node, int k){
        if(node==NULL)
            return false;
        if(st.count(k-node->val))
            return true;
        else
            st.insert(node->val);
        return find(node->left,k) || find(node->right,k);
    }
};