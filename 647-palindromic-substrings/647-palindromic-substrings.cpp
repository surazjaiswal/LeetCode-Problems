class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        bool dp[n][n];
        int cnt=0;
        for(int g=0;g<n;g++){
            for(int i=0,j=g;i<n && j<n;i++,j++){
                if(g==0){
                    dp[i][j]=true;
                }
                else if(g==1){
                    if(s[i]==s[j]){
                        dp[i][j]=true;
                    }else{
                        dp[i][j]=false;
                    }
                }
                else{
                    if(s[i]==s[j] && dp[i+1][j-1]){
                        dp[i][j]=true;
                    }else{
                        dp[i][j]=false;
                    }
                }
                if(dp[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};