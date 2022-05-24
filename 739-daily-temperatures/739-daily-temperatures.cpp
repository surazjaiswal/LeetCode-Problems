class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        int n=temp.size();
        stack<int> stk;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            while(!stk.empty() && temp[stk.top()] < temp[i]){
                ans[stk.top()] = i - stk.top();
                stk.pop();
            }
            
            stk.push(i);
        }
        
        return ans;
    }
};