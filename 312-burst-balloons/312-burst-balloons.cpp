class Solution {
public:
    vector<vector<int>> dp;
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n,vector<int> (n,-1));
        return solve(nums,0,nums.size()-1,1,1);
    }
    
    
    int solve(vector<int> &nums,int i,int j,int left, int right){
        // no element left to contribute
        if(i>j)
            return 0;
        
        // check if already solved for this configuration
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(i==j)
            return left*nums[i]*right; // single element left, it will say take my contribution along with the support of left and right
        
        int ans = 0; // for taking max amount of win from everyones contribution
        for(int k=i;k<=j;k++){
            // now every kth element says now my turn to burst at last 
            // rest of the left and right part give your maximum 
            // kth element also signifies as I will burst at last so
            // I am there to provide support to left and right sub-problems
            // so when any element getting brusted do consider my contribution as I am your neigbhour element
            // since I have decided to brust at last
            
            int leftAns = solve(nums,i,k-1,left,nums[k]);
            int rightAns = solve(nums,k+1,j,nums[k],right);
            int kthAns = left*nums[k]*right; // basically, k'th is last to brust so its contribution is like 1 * nums[k] * 1;
            
            int currAns = leftAns + kthAns + rightAns;
            
            ans = max(ans,currAns);
            
        }
        return dp[i][j] = ans;
    }
};