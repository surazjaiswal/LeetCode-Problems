class Solution
{
    public:
        // map<int,vector<pair<int,int>>> mp;
        int dp[55][55][55];
        long long mod = 1e9 + 7;
        int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
        {
            memset(dp,-1,sizeof(dp));
            int ans = solve(ans, m, n, maxMove, startRow, startColumn);
            
            // for(auto it : mp){
            //     for(auto p : it.second)
            //         cout<<it.first<< " "<<p.first<<" "<<p.second<<endl;
            //     cout<<endl;
            // }
            
            return ans;
        }

    int solve(int &ans, int m, int n, int maxMove, int i, int j)
    {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return 1;

        if (maxMove <= 0)
            return 0;
        
        if(dp[i][j][maxMove] != -1)
            return dp[i][j][maxMove];

        int a = solve(ans, m, n, maxMove - 1, i, j + 1); // right
        int b = solve(ans, m, n, maxMove - 1, i + 1, j); // down
        int c = solve(ans, m, n, maxMove - 1, i, j - 1); // left
        int d = solve(ans, m, n, maxMove - 1, i - 1, j); // up
        
        return dp[i][j][maxMove] = (a % mod + b % mod + c % mod + d % mod) % mod;
    }
};