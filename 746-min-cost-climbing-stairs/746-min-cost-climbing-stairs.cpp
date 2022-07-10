class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,0);
        dp[0] = cost[0], dp[1] = cost[1];
        for(int i=2;i<n;i++){
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }
        
        return min(dp[n-1],dp[n-2]);
        
        /*
        int n = cost.size();
        int a = cost[0];
        int b = cost[1];
        int c;
        for(int i=2;i<n;i++){
            c = cost[i] + min(a,b);
            a=b;
            b=c;
        }
        return min(a,b);
        */
    }
};