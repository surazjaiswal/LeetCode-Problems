class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0,j=0;
        while(i<nums.size()){
            if(nums[i]%2==0){
                swap(nums[i],nums[j]);
                j++;
            }
            i++;
        }
        return nums;
    }
};