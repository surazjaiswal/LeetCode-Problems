class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size()-1;
        vector<int> dp(n+1,-1);
        return rob(n,nums,dp);
        // return max(rob(n,nums,dp),rob(n-1,nums,dp));
    }
    
    int rob(int n,vector<int> &nums,vector<int> &dp){
        if(n<0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n] = max(nums[n]+rob(n-2,nums,dp),rob(n-1,nums,dp));
    }
};