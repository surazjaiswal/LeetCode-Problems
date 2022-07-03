class Solution {
public:
    string minWindow(string s, string t) {
        int s_len = s.length(); // length of string 
        int t_len = t.length(); // length of pattern
        
        // if length of pattern is more than length of string
        // then no pattern will be found in string
        // if(t_len > s_len)
        //     return  "";
        
        // map for having the count of matched char in pattern and string
        unordered_map<char,int> s_mp,t_mp;
        for(char c : t)
            t_mp[c]++;
        
        int cnt = 0; // count for counting number of chars matched in window for pattern in string
        int startIdx = -1; // for storing the start index of found window
        int min_win_size = s_len; // take ans as max size of len
        int i=0,j=0;
        
        while(j<s_len){
            
            // adding current char to map string
            char chr = s[j];
            s_mp[chr]++;
            
            // check if current char is required or not, for the pattern window
            // check if current char's frequency is enough for the pattern or not
            if(t_mp[chr] && s_mp[chr] <= t_mp[chr]){
                // so the current char is present in our pattern
                // and its frequency is less than required 
                // so we add it to our count
                cnt++;
            }
            
            // now check if cnt == length of pattern
            // that means pattern has been found or not
            if(cnt == t_len){
                // if equal to target length
                // then now we should try to get min possible window that contain target
                // by shrinking the curr_window and removing unwanted chars
                while(t_mp.count(s[i]) == 0 || s_mp[s[i]] > t_mp[s[i]]){
                    s_mp[s[i]]--;
                    i++;
                }
                
                // now at this position our window is smallest and contains the required pattern
                int curr_win_size = j - i + 1;
                if(curr_win_size <= min_win_size){
                    min_win_size = curr_win_size;
                    startIdx = i;  // starting index of current min window
                }
            }
            
            j++;
        }
        
        // check if min window found or not
        if(startIdx == -1)
            return "";
        
        return s.substr(startIdx,min_win_size);
        
    }
};