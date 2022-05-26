class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        string ans="";
        stack<string> stk;
        for(int i=0;i<s.length();i++){
             if(isdigit(s[i])){
                int num=0;
                while(i<n && isdigit(s[i])){
                    num = num*10 + s[i]-'0';
                    i++;
                }
                 stk.push(to_string(num));
                 i--;
            }
            else if(isalpha(s[i])){
                string str = "";
                while(i < n && isalpha(s[i])){
                    str += s[i++];
                }
                stk.push(str);
                i--;
            }
            else if(s[i] == '['){
                stk.push("[");
            }
            else if(s[i] == ']'){
                string str="";
                while(stk.top() != "["){
                    str = stk.top() + str;
                    stk.pop();
                }
                stk.pop();
                int times = stoi(stk.top());
                stk.pop();
                string newStr = "";
                while(times--){
                    newStr += str;
                }
                stk.push(newStr);
            }  
        }
        while(stk.size()){
            ans = stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};