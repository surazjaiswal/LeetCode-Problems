class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stk1,stk2;
        
        for(char c : s){
            if(c == '#'){
                if(!stk1.empty())
                    stk1.pop();
            }
            else{
                stk1.push(c);
            }
        }
        
        string str1;
        while(!stk1.empty()){
            char ch = stk1.top();
            stk1.pop();
            str1 += ch;
        }
        
        for(char c : t){
            if(c == '#'){
                if(!stk2.empty())
                    stk2.pop();
            }
            else{
                stk2.push(c);
            }
        }
        
        string str2;
        while(!stk2.empty()){
            char ch = stk2.top();
            stk2.pop();
            str2 += ch;
        }
        
        if(str1 == str2)
            return true;
        return false;
        
    }
};