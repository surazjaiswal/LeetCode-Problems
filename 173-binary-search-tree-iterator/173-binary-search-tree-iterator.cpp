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
class BSTIterator {
public:
    stack<TreeNode*> stk;
    BSTIterator(TreeNode* root) {
        traverse(root);
    }
    
    int next() {
        TreeNode* top = stk.top();
        stk.pop();
        traverse(top->right);
        return top->val;
    }
    
    bool hasNext() {
        if(stk.size())
            return true;
        return false;
    }
    
    void traverse(TreeNode* root){
        if(!root)
            return;
        stk.push(root);
        traverse(root->left);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */