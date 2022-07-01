class Solution {
public:
    int tribonacci(int n) {
        
        if(n==0)
            return 0;
        if(n==1 || n==2)
            return 1;
        
        int a=0,b=1,c=1,d;
        while((n--) > 2){
            d = a+b+c;
            a=b;
            b=c;
            c=d;
        }
        
        return d;
        
//         int dp[40];
//         memset(dp,0,sizeof(dp));
//         if(n==0)
//             dp[n]=0;
//         if(n==1)
//             dp[n]=1;
//         if(n==2)
//             dp[n]=1;
//         dp[0]=0,dp[1]=1,dp[2]=1;
//         for(int i=3;i<=n;i++)
//                 dp[i]=dp[i-3]+dp[i-2]+dp[i-1];
//         return dp[n];
    }
};