class Solution {
public:
    int numMatchingSubseq(string str, vector<string>& words) {
        
        int cnt = 0;
        map<string,int> mp;
        
        for(auto s : words)
            mp[s]++;
        
        for(auto it : mp){
            if(isSubsequence(it.first,str)){
                cnt += it.second;
            }
        }
        
        return cnt;
    }
    
    bool isSubsequence(string s, string str) {
        
        int i=0,j=0;
        
        while(i<s.length() && j<str.length()){
            if(s[i] == str[j])
                i++;
            j++;
        }
        
        return i==s.length();
    }
};