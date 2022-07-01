class Solution {
public:
    int fib(int n) {
        int dp[50];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            if(i<=2){
                dp[i]=1;
                continue;
            }
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};