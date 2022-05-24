class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int> stk;
        vector<int> ans(n,0);
        for(int i=n-1;i>=0;i--){
            int temp = temperatures[i];
            
            while(!stk.empty() && temp >= temperatures[stk.top()])
                stk.pop();
            
            if(!stk.empty()){
                ans[i] = stk.top()-i;
            }
            
            stk.push(i);
            
        }
        
        return ans;
        
    }
};