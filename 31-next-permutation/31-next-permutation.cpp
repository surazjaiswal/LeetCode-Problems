class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-1;
        // for non-decreasing suffix
        while(i>0 && nums[i-1]>=nums[i]){
            i--;
        }
        // now i is the max value of suffix
        if(i<=0){
            // this means given premutation is already in max form
            // then return the minimum form of that, by sorting it
            sort(nums.begin(),nums.end());
            return;
        }
        // nums[i-1] is the pivot element
        // now find the next larger value of pivot in the nums array from right side
        int j=nums.size()-1;
        while(j>=0 && nums[j]<=nums[i-1]){
            j--;
        }
        // now j is at next max of pivot
        // now swap both values
        swap(nums[i-1],nums[j]);
        reverse(nums.begin() + i,nums.end());
    }
};