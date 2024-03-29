class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i : nums){
            if(i>0)
                mp[i]++;
        }
        
        int i=1;
        while(mp[i]){
            i++;
        }
        
        return i;
    }
};