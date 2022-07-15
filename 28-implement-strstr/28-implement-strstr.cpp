class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(needle.empty())
            return 0;
        
        if(needle.size() > haystack.size())
            return -1;
        
        int i=0,j=0;
        int idx = 0;
        while(j<haystack.size()){
            if(haystack[j] != needle[i]){
                j++;
                continue;
            }
            
            idx = j;
            while(j<haystack.size() && haystack[j] == needle[i]){
                i++,j++;
                if(needle.size() == i)
                    return idx;
            }
            i=0;
            j=idx+1;
        }
        return -1;
    }
};