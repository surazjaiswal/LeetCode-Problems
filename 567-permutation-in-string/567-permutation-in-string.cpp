class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        if(n1 > n2)
            return false;

        vector<int> s1_mp(26,0),s2_mp(26,0);
        for(int i=0;i<n1;i++){
            s1_mp[s1[i]-'a']++;
            s2_mp[s2[i]-'a']++;
        }
        
        if(s1_mp == s2_mp)
            return true;
        
        int i=1,j=n1;
        while(j < n2){
            s2_mp[s2[j]-'a']++;
            s2_mp[s2[i-1]-'a']--;
            
            if(s1_mp == s2_mp)
                return true;
            i++;
            j++;
        }
        return false;        
    }
};