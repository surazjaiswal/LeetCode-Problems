class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int ans = 0;
        int startIdx = 0, currIdx = 0;
        while(currIdx < s.length()){
            if(mp.count(s[currIdx]) && mp[s[currIdx]] >= startIdx){
                // this is the duplicate in current substring
                // now move the startIdx to 1 + idx of duplicate Idx
                startIdx = 1 + mp[s[currIdx]];
            }
            // else add current char to mp with its idx
            // and also go on calculating the len of substring found till now
            mp[s[currIdx]] = currIdx;
            ans = max(ans,currIdx - startIdx + 1);
            currIdx++;
        }
        return ans;
    }
};