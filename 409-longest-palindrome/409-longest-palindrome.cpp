class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> mp;
        for(char c : s){
            mp[c]++;
        }
        int ans=0;
        int oddCount=0;
        for(auto it : mp){
            if(it.second % 2 ==0){
                ans += it.second;
            }else{
                int cnt = it.second - 1;
                ans += cnt;
                oddCount++;
            }
        }
        
        if(oddCount>0)
            return ans+1;
        return ans;
        
    }
};