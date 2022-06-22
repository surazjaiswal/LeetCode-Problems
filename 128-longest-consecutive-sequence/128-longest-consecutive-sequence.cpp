class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i : nums)
            mp[i]++;
        int max_len=0;
        for(int i : nums){
            if(mp[i-1]==0){
                // current number can start the chain
                int cnt=0,num=i;
                while(mp[num]){
                    cnt++;
                    num++;
                }
                max_len = max(max_len,cnt);
            }
        }
        return max_len;
    }
};