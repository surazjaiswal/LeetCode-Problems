class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[p.length()+1][s.length()+1]; // row -> pattern & col -> string 
        
        // initialization
        {
            dp[0][0] = true; // blank pattern statisfies blank string

            // for blank string and given pattern
            for(int k=1;k<=p.length();k++){
                if(p[k-1] == '*')
                    dp[k][0] = dp[k-2][0];
                else
                    dp[k][0] = false;
            }

            // for blank patterm and given string
            for(int k=1;k<=s.length();k++){
                dp[0][k] = false;
            }

        }
        
        for(int i=1;i<=p.length();i++){
            for(int j=1;j<=s.length();j++){
                if(p[i-1] == s[j-1]){
                    // same chars, now the diagonal for previous string pattern ans
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[i-1] == '.'){
                    // current pattern char is '.' which can match any (for now curr char) char in string
                    // so now the diagonal for previous string pattern ans
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[i-1] == '*'){
                    // current pattern char is '*', for this we need to check 2 rows above
                    // which is the ans if star and it previous char doesn't contribute then,
                    // will the pattern left can produce/match the string till current index
                    dp[i][j] = dp[i-2][j];
                    
                    // now if above can not then check if adding prev char of * match the string
                    // that is check if the added char is same as last char of string or not
                    // if its not same then continue as it will not contribute any to ans
                    // if its same then we have last char match, now assume last chars are removed
                    // now we have to check if the rest of string and pattern including the * pattern
                    // this makes the sub problem we just did one step before i.e. (j-1)th index
                    
                    // take or (||) of the current ans stored and prev ans from j-1 th index
                    // since we can also have ans from 2 row above (above condition)
                    if(p[i-2] == '.' || p[i-2] == s[j-1])
                        dp[i][j] = dp[i][j] || dp[i][j-1];
                }else{
                    // the last case is that chars doesn't match
                    dp[i][j]=false;
                }
            }
        }
        
        return dp[p.length()][s.length()];
        
    }
};