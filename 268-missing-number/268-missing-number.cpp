class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        for(auto n : nums){
            if(n != i)
                return i;
            i++;
        }
        return i;
    }
};