class Solution {
public:
    int dp[35][35];
    vector<vector<int>> generate(int numRows) {
        memset(dp,-1,sizeof(dp));
        int n=numRows;
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            vector<int> vt;
            for(int j=0;j<=i;j++){
                vt.push_back(nCr(i,j));
            }
            ans.push_back(vt);
        }
        
        return ans;
    }
    
    int nCr(int n, int r){
        if(r==0 || r==n)
            return 1;
        if(r==1 || n-r==1)
            return n;
        if(dp[n][r]!=-1)
            return dp[n][r];
        return dp[n][r]=nCr(n-1,r-1)+nCr(n-1,r);
    }
};