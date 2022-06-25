class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt=0;
        // starting from two because if n=1 -> true, 
        // if n==2 -> only one required change can easily be applied
        for(int i=1;i<nums.size() && cnt<=1;i++){
            if(nums[i-1] > nums[i]) {
                cnt++;
                if(i-2 < 0 || nums[i-2] <= nums[i]){
                    nums[i-1] = nums[i];
                }else
                    nums[i] = nums[i-1];
            }
        }
        return (cnt <= 1);
    }
};