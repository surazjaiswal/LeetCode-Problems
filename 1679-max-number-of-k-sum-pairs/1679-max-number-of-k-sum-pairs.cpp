class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int cnt=0;
        for(int i : nums){
            int x = k - i;
            if(mp[x] > 0){
                mp[x]--;
                cnt++;
            }else{
                mp[i]++;
            }
        }
        return cnt;
    }
};