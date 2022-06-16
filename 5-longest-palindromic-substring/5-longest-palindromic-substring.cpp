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
        // if same then we need to check if string in the middle of both the char are pallindrome or not
        // if pallindrome then this complete selected string will be pallindrome else it will not be
        // and the important part here is as we progress we are already making check for pallindrome of the middle subtrings
        // from this we will get the size of largest pallindrome, and starting index
        // then return the the substring of that size, with starting index
        
        
        int n = s.length(); // size of string
        int dp[n][n]; // making dp for tabulation of subtrings
        int len = 0, idx = -1;
        
        // following gap strategy
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g==0){
                    // single char is always pallindrome
                    dp[i][j]=1;
                }else if(g==1){
                    // if both char are equal then its a pallindrome, else not pallindrome
                    if(s[i] == s[j])
                        dp[i][j]=1;
                    else 
                        dp[i][j]=0;
                }else{
                    // if both start & end char are equal and the middle substring is pallindrome then this selected string will pallindrome
                    if(s[i] == s[j] && dp[i+1][j-1])
                        dp[i][j]=1;
                    // else not pallindrome
                    else
                        dp[i][j]=0;
                }
                
                // if pallindrome, then check length and compare it with previous ans
                // also upatde the len ans starting index
                if(dp[i][j]){
                    int sz = j - i + 1;
                    if(sz > len){
                        len = sz;
                        idx = i;
                    }
                }
            }
        }
        // extracting the required substring
        string ss = s.substr(idx,len);
        return ss;
    }
};