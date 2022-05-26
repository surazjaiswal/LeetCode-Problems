class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length()==k)
            return "0"; // removing all the elements
        
        stack<char> stk;
        for(char ch : num){
            while(k && !stk.empty() && int(stk.top()) > int(ch)){
                stk.pop();
                k--;
            }
            stk.push(ch);
        }
        
        if(k > 0){
            while(k--){
                stk.pop();
            }
        }
        // now removing leading zeros if present
        stack<char> stk_new;
        while(!stk.empty()){
            stk_new.push(stk.top());
            stk.pop();
        }
        while(stk_new.top()=='0' && stk_new.size() != 1){
            stk_new.pop();
        }
        // final answer
        string ans="";
        while(!stk_new.empty()){
            ans += stk_new.top();
            stk_new.pop();
        }
        return ans;
        
    }
};