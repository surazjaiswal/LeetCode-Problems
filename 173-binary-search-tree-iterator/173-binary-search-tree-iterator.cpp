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
    vector<TreeNode*> nodes;
    int i,n;
    BSTIterator(TreeNode* root) {
        inOrder(root);
        i=0;
        n=nodes.size();
    }
    
    int next() {
        ++i;
        int num = nodes[i-1]->val;
        return num;
    }
    
    bool hasNext() {
        if(i<n)
            return true;
        return false;        
    }
    
    void inOrder(TreeNode *root){
        if(!root)
            return;
        
        inOrder(root->left);
        nodes.push_back(root);
        inOrder(root->right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */