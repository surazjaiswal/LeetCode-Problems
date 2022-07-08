class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ns = s.length(), np = p.length();
        
        // if size of string is less than size of pattern
        if(ns < np)
            return {};
        // here we are using vector for hashing purpose, mapping used is count of chars
        vector<int> sv(26,0), pv(26,0), ans; // sv: string vector, pv: pattern vector
        
        // first populating the sv and pv with numbers of chars present respectively
        for(int i=0;i<np;i++){
            pv[p[i]-'a']++;
            sv[s[i]-'a']++;
        }
        
        // check if both vectors are equal
        // if found equal, this means that current sv (vector) has a anagram for given pattern
        // ans this anagram started at index 0, add this to ans
        if(pv == sv){
            ans.push_back(0);
        }
        
        // here we have a window of size np in s, which starts at i=0 to j=np-1
        // now using sliding window concept 
        // we start next window from i=1,j=ns
        
        int i=1,j=np;
        
        while(j<ns){
            sv[s[i-1]-'a']--; // removing the last used char count, since it is not part of current window now
            sv[s[j]-'a']++; // add count of char at j as its now part of current window;
            
            // you will see that in sv we are maintaining the count of chars in current window only
            // now check if current window's vector_of_char_count matches with vector_of_char_count of pattern
            // if matches then add current window's starting index which is 'i'
            if(pv == sv)
                ans.push_back(i); // adding the starting index of current window
            
            i++,j++; // for window sliding
        }        
        return ans;
    }
};