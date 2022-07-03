class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        int n=nums.size();
        
        if(n==1)
            return 1; // size of nums is 1, then that single number will alone form the wiggle
        if(n==2)
            return (nums[0] == nums[1])? 1 : 2; // is two elements in the nums, then if both are same then wiggle subseq size will be 1, and if both different then size will be 2
        
        int cnt=(nums[0] == nums[1])? 1 : 2;
        int prev_diff = nums[1] - nums[0];
        for(int i=2;i<n;i++){
            int curr_diff = nums[i] - nums[i-1];
            if((curr_diff < 0 && prev_diff >=0) || (curr_diff > 0 && prev_diff <= 0)){
                cnt++;
                prev_diff = curr_diff;
            }
        }
        
        return cnt;
    }
    
};