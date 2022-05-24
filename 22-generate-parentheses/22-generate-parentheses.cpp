class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        char str[20];
        generateBrackets(str,0,0,0,n);
        return ans;
    }
    
    void generateBrackets(char *str,int i,int open, int close,int n){
        // base case
        if(i == n*2){
            str[i]='\0';
            ans.push_back(str);
            return;
        }
        // recursion case
        if(open < n){
            str[i] = '(';
            generateBrackets(str,i+1,open+1,close,n);
        }
        if(close < open){
            str[i] = ')';
            generateBrackets(str,i+1,open,close+1,n);
        }
        return;
    }
};