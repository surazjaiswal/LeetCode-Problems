class Solution {
public:
    string removeDuplicates(string s) {
        stack<pair<char,int>> stk;
        
        for(char c : s){
            if(!stk.empty() && stk.top().first == c){
                stk.push({c,stk.top().second + 1});
            }else{
                stk.push({c,1});
            }
            
            if(!stk.empty() && stk.top().second == 2){
                int k=2;
                while(k--){
                    stk.pop();
                }
            }
        }
        
        string ans = "";
        while(!stk.empty()){
            ans += stk.top().first;
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};