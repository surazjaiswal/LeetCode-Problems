class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // the idea is using xor operation since xor'ing between two same elements leads to 0 ie nullifying
        // in xor the order doesn't matter            
        // ex : 3^(3^0)^(0^1)^(1^2) = 3
            
        int n = nums.size();
        int ans = n;
        
        
        for(int i=0;i<n;i++){
            ans ^= nums[i];
            ans ^= i;
        }
        return ans;
    }
};