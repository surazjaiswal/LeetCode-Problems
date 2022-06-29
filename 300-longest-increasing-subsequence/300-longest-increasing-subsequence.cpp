class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMins(n,1);
        int max_len = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i]){
                    leftMins[i] = max(leftMins[i],leftMins[j]+1);
                }
            }
            max_len = max(max_len,leftMins[i]);
        }
        
        return max_len;
    }
};