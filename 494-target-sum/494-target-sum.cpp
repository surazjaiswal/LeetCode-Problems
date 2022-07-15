class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // problem is similar to finding two subset diff of sum is equal to given target 
        // divide arr into 2 having sum s1 & s2
        // we need to find count of (s1 - s2 == target)
        
        
        // here two things are const target (which is req diff for our case) & total sum of the array
        // lets say
        // s1 + s2 = total_sum --> range
        // s1 - s2 = target
        // adding both the equations, then we have
        // s1 = (target + total_sum)/2
        
        // so the problem now reduces to finding number of subsets with sum s1
        
        int sum = 0;
        for(int i : nums)
            sum += i;
        
        // if target is greater than range (target sum)
        if(target > sum)
            return 0;
        
        // if range can't be divided 
        if((target+sum)%2 != 0)
            return 0;
        
        
        int s = (target + sum)/2;
        int n = nums.size();
        
        if(s < 0)
            return 0;
        
        int dp[n+1][s+1];
        
        // can empty arr make sum [0,s] --> false
        for(int k=0;k<=s;k++)
            dp[0][k] = 0;
        
        // can non-empty arr make sum = 0 --> true
        for(int k=0;k<=n;k++)
            dp[k][0] = 1;
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=s;j++){
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return dp[n][s];
    }
};
