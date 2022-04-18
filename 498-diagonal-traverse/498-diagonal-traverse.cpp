class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        int m=mat.size();
        int n=mat[0].size();
        
        if(m==1)
            return mat[0];
        if(n==1){
            vector<int> vt;
            for(int i=0;i<m;i++)
                vt.push_back(mat[i][0]);
            return vt;
        }
        

        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            vector<int> vt;
            for(int j=0;j<=n;j++){
                if(i-j >= 0 && j>=0 && i-j<m && j<n){
                    vt.push_back(mat[i-j][j]);
                }
            }
            ans.push_back(vt);
        }
        
        for(int j=1;j<n;j++){
            vector<int> vt;
            int c=j;
            for(int i=m-1;i>=0;i--){
                if(i>= 0 && c>=0 && i<m && c<n){
                    vt.push_back(mat[i][c++]);
                }
            }
            ans.push_back(vt);
        }
        
        vector<int> res;
        for(int i=0;i<ans.size();i++){
            if(i&1)
                reverse(ans[i].begin(),ans[i].end());
            for(int j : ans[i])
                res.push_back(j);
        }
           
        
        return res;
    }
};