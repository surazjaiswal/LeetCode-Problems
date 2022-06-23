class Solution {
public:
    int integerReplacement(int n) {
        return solve(n);
    }
    
    int solve(int n) {
        if(n == 1)
            return 0;
        
        if(n&1){
            if(n != INT_MAX) // to avoid INT overflow
                return 1 + min(solve(n-1), solve(n+1));
            else
                return solve(n-1); // since this case will run only for INT_MAX only, so no extra operation 
        }else{
            return 1 + solve(n/2);
        }
    }
};