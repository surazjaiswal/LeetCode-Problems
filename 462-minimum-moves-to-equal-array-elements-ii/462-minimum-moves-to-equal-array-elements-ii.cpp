class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i=0,j=n-1;
        int cnt = 0;
        while(i<j){
            cnt += abs(nums[j] - nums[i]);
            i++,j--;
        }
        
        return cnt;
    }
};