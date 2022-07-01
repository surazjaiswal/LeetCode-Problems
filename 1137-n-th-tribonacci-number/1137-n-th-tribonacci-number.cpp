class Solution {
public:
    int tribonacci(int n) {
        
        int dp[40];
        memset(dp,0,sizeof(dp));
        if(n==0)
            dp[n]=0;
        if(n==1)
            dp[n]=1;
        if(n==2)
            dp[n]=1;
        dp[0]=0,dp[1]=1,dp[2]=1;
        for(int i=3;i<=n;i++)
                dp[i]=dp[i-3]+dp[i-2]+dp[i-1];
        return dp[n];
    }
};