class Solution {
public:
    int climbStairs(int n) {
        
        if(n<=2)
            return n;
        
        int a,b,c; // a->n-2, b->n-1, c->n
        a=1,b=2;
        for(int i=3;i<=n;i++){
            c=a+b;
            a=b;
            b=c;
        }
        return c;
        
        // int dp[50];
        // dp[0]=1,dp[1]=1;
        // for(int i=2;i<=n;i++){
        //     dp[i] = dp[i-1]+dp[i-2];
        // }
        // return dp[n];
    }
};