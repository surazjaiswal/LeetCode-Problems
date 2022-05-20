class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int diff = INT_MAX;
        int csum;
        for(int i=0;i<=nums.size()-3;i++){
            int sum = 0;
            int j = i+1,k=nums.size()-1;
            sum += nums[i] + nums[j] + nums[k];
            while(j<k){
                if(abs(sum - target) < diff){
                    diff = abs(sum-target);
                    csum=sum;
                }
                if(sum < target){
                    sum -= nums[j];
                    sum += nums[++j];
                }
                else if(sum > target){
                    sum -= nums[k];
                    sum += nums[--k];
                }
                else{
                    return sum;
                }
            }
        }
        return csum;
    }
};