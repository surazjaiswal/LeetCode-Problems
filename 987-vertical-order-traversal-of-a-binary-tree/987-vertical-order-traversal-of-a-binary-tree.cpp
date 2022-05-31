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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        if(!root)
            return {};
        
        map<int,map<int,vector<int>>> mp; // < dist < level > val_vt > >
        queue<pair<TreeNode*,pair<int,int>>> q; // <node<dist,level>>
        
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it  = q.front();
            q.pop();
            
            TreeNode *node = it.first;
            int dist = it.second.first;
            int level = it.second.second;
            
            mp[dist][level].push_back(node->val);
            
            if(node->left)
                q.push({node->left,{dist-1,level+2}});
            
            if(node->right)
                q.push({node->right,{dist+1,level+1}});
        }
        
        vector<vector<int>> ans;
        for(auto i : mp){
            vector<int> vt;
            for(auto j : i.second){
                sort(j.second.begin(),j.second.end());
                for(auto k : j.second)
                    vt.push_back(k);
            }
            ans.push_back(vt);
        }
        
        return ans;
    }
    
};