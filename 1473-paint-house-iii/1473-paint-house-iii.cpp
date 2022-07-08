class Solution {
public:
    int INF;
    int dp[101][101][21];
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        INF = 1e6+1;
        memset(dp,-1,sizeof(dp));
        int ans = solve(houses,cost,m,n,target,0,0,0);
        if(ans < INF)
            return ans;
        return -1;
    }
    
    int solve(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target,int i,int nbr,int left){
        // base case
        if(i == m)
            return (nbr == target)? 0 : INF;
        
        if(nbr > target)
            return INF;
        
        if(dp[i][nbr][left] != -1)
            return dp[i][nbr][left];
        
        // recursive case 
        // 2 cases if ith house is not colored
        if(houses[i] == 0){
            // coloring ith house with each possible color
            int min_cost = INF;
            for(int c=1;c<=n;c++){
                int new_nbr = nbr;
                if(c != left)
                    new_nbr += 1;
                min_cost = min(min_cost,cost[i][c-1] + solve(houses,cost,m,n,target,i+1,new_nbr,c));
            }
            return dp[i][nbr][left] = min_cost;
        }else{
            // ith house is not colored
            int new_nbr = nbr;
            if(houses[i] != left)
                new_nbr += 1;
            return dp[i][nbr][left] = solve(houses,cost,m,n,target,i+1,new_nbr,houses[i]);
        }
    }
};