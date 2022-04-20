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
​
/**
* Your BSTIterator object will be instantiated and called as such:
* BSTIterator* obj = new BSTIterator(root);
* int param_1 = obj->next();
* bool param_2 = obj->hasNext();
*/
```
​
​
https://leetcode.com/problems/binary-search-tree-iterator/discuss/1430547/C%2B%2B-Simple-Solution-using-Stack-O(h)-Time-Complexity-(-with-Diagrammatic-Explanation-)