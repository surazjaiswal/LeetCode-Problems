class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;
        sort(s1.begin(),s1.end());
        int i=0;
        while(i <= s2.length() - s1.length()){
            string str = s2.substr(i,s1.length());
            sort(str.begin(),str.end());
            // cout<<str<<" ";
            if(str == s1)
                return true;
            i++;
        }
        return false;
    }
};