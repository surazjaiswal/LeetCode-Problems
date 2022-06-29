class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        
        // in this we need to use bidirectional dp
        // to find number of lesser number of numbers towards its left & right including itself
        // this can be using help of two lists, leftPart, rightPart
        // and then find length of longest bitonic subsequence for every element (leftPart[i] + rightPart[i] - 1) then return max of them
        // and for this problem return the difference of longest bitonic subsequnce and size of nums
        
        int n = nums.size();
        
        vector<int> leftNums(n,1), rightNums(n,1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i])
                    leftNums[i] = max(leftNums[i], leftNums[j] + 1);
            }
        }
        
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(nums[j] < nums[i])
                    rightNums[i] = max(rightNums[i], rightNums[j] + 1);
            }
        }
        
        int max_len = 0;
        for(int i=0;i<n;i++)
            if(leftNums[i]!=1 && rightNums[i]!=1)
                max_len = max(max_len,leftNums[i] + rightNums[i] - 1);
        
        // cout<<max_len<<endl;
        return n - max_len;
        
    }
};