class Solution {
public:
    int characterReplacement(string s, int k) {
        int max_len = 0;
        int max_count = 0;
        int i=0,j=0;
        vector<int> vt(26,0);
        while(j<s.length()){
            vt[s[j]-'A']++;
                        
            max_count = max(max_count, vt[s[j]-'A']);
            if((j-i+1) - max_count <= k){
                max_len = max(max_len, j-i+1);
                j++;
            }
            else{
                vt[s[i]-'A']--;
                vt[s[j]-'A']--;
                i++;
            }
        }
        
        return max_len;
    }
};