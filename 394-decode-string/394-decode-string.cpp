class Solution {
public:
    string decodeString(string s) {
        int n = s.length(); 
        stack<string> stk; // to everthing init literly everything ;)
        int i=0;
        while(i<n){
            // if current char is digit, then extract the number from it, this is the number of times later used
            if(isdigit(s[i])){
                int num = 0;
                while(isdigit(s[i])){
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--; // reduce i since it is at i+1 because of prev while loop check
                stk.push(to_string(num)); // push times number to stk
            }
            // open bracket symbolizes new string ahead to decode
            else if(s[i] == '['){
                stk.push("[");
            }
            // is current char is alpha, extract the complete string till its available, before closing bracket
            else if(isalpha(s[i])){
                string str = "";
                while(isalpha(s[i])){
                    str += s[i];
                    i++;
                }
                stk.push(str); // push string to stk
                i--; // reduce i since it is at i+1 because of prev while loop check
            }
            
            // now when yout hit closing bracket, then its time to extract the string from stk and decode it 
            else if(s[i] == ']'){
                // extract complete string from stk till its available
                string str = "";
                while(stk.top() != "["){
                    str = stk.top() + str;
                    stk.pop();
                }
                stk.pop(); // this pops the open bracket from the stk, this implies complete string extracted for now
                int times = stoi(stk.top()); // then next element in stk is the number of times string needs to be decoded
                stk.pop(); // pop it
                string newStr = ""; // make new string of decode ans
                while(times--){
                    newStr += str; 
                }
                stk.push(newStr); // now for further decoding
            }
            i++; // move to next element in given string
        }
        // now pop all decoded strings from the stk and add it accordingly to ans;
        string ans = ""; 
        while(stk.size()){
            ans = stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};