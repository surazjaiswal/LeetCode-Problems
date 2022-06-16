class Solution {
public:
    string longestPalindrome(string s) {
        // using tabulation method 
        // the main concept here used is to first generation of substring (hypothetically in tabulation)
        // three main cases include
        // single character string is always pallindrome
        // 2 char string both same char is pallindrome
        // now the 3rd important case
        // if string size more than 2 
        // then check if first and last char are same or not 
        // if same then we need to check if string in the mid of both the char are same or not
        // if same then this complete string will be pallindrome else it will not be
        // and the import part here is as we progress we are already making check for pallindrome of the middle subtrings
        // from this we will get the size of largest pallindrome, and starting index
        // then return the the substring of that size
        
        
        int n = s.length(); // size of string
        int dp[n][n]; // making dp for tabulation of subtrings
        int len = 0, idx = -1;
        
        // following gap strategy
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g==0){
                    dp[i][j]=1;
                }else if(g==1){
                    if(s[i] == s[j])
                        dp[i][j]=1;
                    else 
                        dp[i][j]=0;
                }else{
                    if(s[i] == s[j] && dp[i+1][j-1])
                        dp[i][j]=1;
                    else
                        dp[i][j]=0;
                }
                
                if(dp[i][j]){
                    int sz = j - i + 1;
                    if(sz > len){
                        len = sz;
                        idx = i;
                    }
                }
            }
        }
        string ss = s.substr(idx,len);
        return ss;
    }
};