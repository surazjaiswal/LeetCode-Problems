class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int tempMax=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            tempMax=max(sum,tempMax);
            if(sum<0)
                sum=0;
        }
        return tempMax;
    }
};