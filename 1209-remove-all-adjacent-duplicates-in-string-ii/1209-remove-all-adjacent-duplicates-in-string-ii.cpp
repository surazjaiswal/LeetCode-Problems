class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> stk;
        
        for(char c : s){
            if(!stk.empty() && stk.top().first == c){
                stk.push({c,stk.top().second + 1});
            }else{
                stk.push({c,1});
            }
            
            if(!stk.empty() && stk.top().second == k){
                int t = k;
                while(t--){
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