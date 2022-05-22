class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> index(26,-1), visited(26,0);
        for(int i=0;i<s.length();i++)
            index[s[i]-'a']=i;
        
        stack<char> stk;
        for(int i=0;i<s.length();i++){
            if(visited[s[i]-'a'])
                continue;
            while(stk.size() && stk.top() > s[i] && index[stk.top()-'a'] > i){
                visited[stk.top()-'a']=0;
                stk.pop();
            }
            stk.push(s[i]);
            visited[s[i]-'a']=1;
        }
        
        string ans="";
        while(!stk.empty()){
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};