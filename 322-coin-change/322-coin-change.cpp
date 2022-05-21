class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int amt = amount;
        vector<int> dp(amt+1,amt+1);
        dp[0]=0;
        for(int i=0;i<=amt;i++){
            for(int j=0;j<coins.size();j++){
                int bal = i - coins[j];
                if(bal==0){
                    dp[i]=1;
                    continue;
                }else if(bal>0){
                    dp[i] = min(dp[i],1+dp[bal]);
                }
            }
        }
        if(dp[amt]==amt+1)
            return -1;
        return dp[amt];
    }
};