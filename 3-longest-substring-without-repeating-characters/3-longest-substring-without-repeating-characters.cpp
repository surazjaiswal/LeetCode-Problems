class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int ans = 0;
        int i=0;
        for(int j=0;j<s.length();j++){
            if(mp.count(s[j]) && mp[s[j]] >= i)
                i = mp[s[j]] + 1;
                        
            mp[s[j]] = j;
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};