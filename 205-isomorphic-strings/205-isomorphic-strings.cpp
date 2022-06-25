class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        map<char,char> mp,mp2;
        
        for(int i=0;i<n;i++){
            if(mp[s[i]] && mp[s[i]]!=t[i])
                return false;
            else
                mp[s[i]] = t[i];
            
            if(mp2[t[i]] && mp2[t[i]]!=s[i])
                return false;
            else
                mp2[t[i]] = s[i];
        }
        return true;
    }
};