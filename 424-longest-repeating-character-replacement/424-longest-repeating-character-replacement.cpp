class Solution {
public:
    int characterReplacement(string s, int k) {
        int max_len = 0;
        int max_count = 0;
        int i=0,j=0;
        vector<int> vt(26,0);
        while(j<s.length()){
            vt[s[j]-'A']++; // adding the new char in window, also incrementing its freqency count
                        
            max_count = max(max_count, vt[s[j]-'A']); // frequency of most frequent char in current window
            
            // if window_size - freq_most_freq_char_int this_window is <= k (max_operation)
            // this difference is the change operation required to make all char same 
            // the max_window size will be then be obtained
            if((j-i+1) - max_count <= k){
                max_len = max(max_len, j-i+1); // max window len till now
                j++; // moving to next char and thereafter adding it to window in next iteration
            }
            else{
                vt[s[j]-'A']--; // so that it is not counted again in next iteration
                vt[s[i]-'A']--; // reducing the count of char at ith postion (start of window) as window size is to be reduced;
                i++;    // now reducing the window size
            }
        }
        
        return max_len;
    }
};