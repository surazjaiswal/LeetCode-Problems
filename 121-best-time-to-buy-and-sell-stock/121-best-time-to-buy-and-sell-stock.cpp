class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxProfit = 0;
        
        stack<int> stk;
        stk.push(prices[0]);
        
        int i=1;
        while(i<n){
            if(prices[i] < stk.top()){
                stk.push(prices[i]);
            }else{
                int profit = prices[i] - stk.top();
                maxProfit = max(maxProfit,profit);
            }
            i++;
        }
        
        return maxProfit;
    }
};