class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_len = s.length();
        int t_len = t.length();
        
        if(s_len==0 && t_len==0)
            return true;
        
        if(s_len==0)
            return true;
        if(t_len==0)
            return false;
        
        int i=0,j=0;
        while(i<s_len && j<t_len && i<=j){
            if(s[i]==t[j]){
                i++,j++;
            }else{
                j++;
            }
        }
        
        if(i==s_len)
            return true;

        return false;
    }
};