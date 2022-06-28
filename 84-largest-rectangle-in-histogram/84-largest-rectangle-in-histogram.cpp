class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int max_ar=0;
        
        vector<int> pre,post;
        pre = preSmaller(heights);
        post = postSmaller(heights);
        
        for(int i=0;i<n;i++){
            int curr_h = heights[i];
            int width_expansion = post[i] - pre[i] - 1;
            int curr_ar = curr_h * width_expansion;
            max_ar = max(max_ar,curr_ar);
        }              
        
        return max_ar;
    }
    
    
    vector<int> preSmaller(vector<int> &heights){
        int n = heights.size();
        stack<int> stk;
        vector<int> vt(n);
        for(int i=0;i<n;i++){
            int curr_h = heights[i];
            if(stk.empty()){
                vt[i]=-1;
            }else{
                while(stk.size() && heights[stk.top()] >= curr_h){
                    stk.pop();
                }
                if(!stk.empty()){
                    vt[i] = stk.top();
                }else{
                    vt[i]=-1;
                }
            }
            stk.push(i);
        }
        return vt;
    }
    
    vector<int> postSmaller(vector<int> &heights){
        int n = heights.size();
        stack<int> stk;
        vector<int> vt(n);
        for(int i=n-1;i>=0;i--){
            int curr_h = heights[i];
            if(stk.empty()){
                vt[i]=n;
            }else{
                while(stk.size() && heights[stk.top()] >= curr_h){
                    stk.pop();
                }
                if(!stk.empty()){
                    vt[i] = stk.top();
                }else{
                    vt[i]=n;
                }
            }
            stk.push(i);
        }
        return vt;
    }
};