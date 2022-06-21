class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp; // <sum,idx>
        mp[0]=-1;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            int r = sum%k;
            
            if(mp.count(r) == 0){
                mp[r] = i;
            }            
            else{
                if(i - mp[r] >= 2)
                    return true;
            }
            
            //  do not update the existing element in the mp
            
            // corner case -> [0,0]
            if(nums[i]==0 && i+1 < nums.size() && nums[i+1]==0)
                return true;
        }
        return false;
    }
};