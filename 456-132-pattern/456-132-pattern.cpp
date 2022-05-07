class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        stack<int> stk;
        int second = INT_MIN;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i] < second)
                  return true;
            while(!stk.empty() && nums[i] > stk.top()){
                second = stk.top();
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
    
   
};