class Solution {
public:
    int fib(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        
        int a = 0, b = 1, c;
        while((n--) > 1){
            c = a + b;
            a = b;
            b = c;
        }
        
        return c;
        
        
        // int dp[50];
        // memset(dp,0,sizeof(dp));
        // for(int i=1;i<=n;i++){
        //     if(i<=2){
        //         dp[i]=1;
        //         continue;
        //     }
        //     dp[i] = dp[i-1] + dp[i-2];
        // }
        // return dp[n];
    }
};