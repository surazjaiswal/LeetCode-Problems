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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return NULL;
        
        TreeNode *root = makeTree(nums,0,n-1);
        return root;
    }
    
    TreeNode *makeTree(vector<int> &nums, int i,int j){
        if(i<=j){
            int idx = getMax(nums,i,j);
            cout<<nums[idx]<<" ";
            TreeNode *node = new TreeNode(nums[idx]);
            node->left = makeTree(nums,i,idx-1);
            node->right = makeTree(nums,idx+1,j);
            return node;
        }
        return NULL;
    }
    
    int getMax(vector<int> &nums,int low,int high){
        int maxVal = -1;
        int idx=0;
        for(int i = low;i<=high;i++){
            if(nums[i] > maxVal){
                maxVal = max(maxVal,nums[i]);
                idx = i;
            }
        }
        return idx;
    }
};