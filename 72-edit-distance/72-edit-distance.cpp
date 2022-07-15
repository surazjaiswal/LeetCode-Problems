class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        
        int dp[n1+1][n2+1];
        
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                if(i == 0){
                    // word1 is empty, therefore number of opr needed is length of word2
                    dp[i][j] = j;
                }
                else if(j == 0){
                    // word2 is empty, therefore number of opr needed is length of word1
                    dp[i][j] = i;
                }
                else{
                    // now both words are non empty
                    // 2 cases
                    // current char's are same, then no extra operation needed
                    if(word1[i-1] == word2[j-1]){
                        dp[i][j] = dp[i-1][j-1];
                    }else{
                        // char's are not same 
                        // here we can perform 3 operations
                        
                        // 1. insert char at the end of s1, which will be same as corresponding char in word2, now check for min opr with one less char in word2 (from end)
                        // 2. delete char at the ith (not in real), now check for the min opr needed for one char less in word1 (from end)
                        // 3. replace char at ith pos, which mean char will become same at there corresponding pos, now check min opr for one char less in both the words
                        int insert_op = 1 + dp[i][j-1];
                        int delete_op = 1 + dp[i-1][j];
                        int replace_op = 1 + dp[i-1][j-1];
                        
                        dp[i][j] = min({insert_op,delete_op,replace_op});
                        
                    }
                }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        
        return dp[n1][n2];
    }
};