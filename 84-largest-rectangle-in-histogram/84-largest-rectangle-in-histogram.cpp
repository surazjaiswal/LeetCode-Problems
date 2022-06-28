class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Here the important observation is that 
        // any rectangle that will be formed will include one bar completly in it... 
        // suppose take bar size 5 from eaxmple one,
        // what is the max amount of contigeous bars it can include to make a bigger reactangle
        // that the the bars whose size is greater than equal to it 
        // condcluding that we need to find what is the max amount of bars a selected bar can include
        // to make max rect area, include bars will be of size greater than equal to it
        
        
        // so for a selected bar we need to find the max extent to which this selected height is available to its both sides
        // this can be done optimally using monotonic stack O(N)
        // separatly for right traverse and left traverse for any bar
        
        // then we will get the extend from leftHeight && rightHeight then multiply it with bar height to get area ;)
        
        
        int n = heights.size();
        vector<int> leftH(n) ,rightH(n);
        getLeftH(heights, leftH);
        getRightH(heights,rightH);
        int max_area = 0;
        for(int i=0;i<n;i++){
            int l = leftH[i];
            int r = rightH[i];
            int len = r - l - 1;
            int area = len*heights[i];
            max_area = max(max_area,area);
        }
        
        return max_area;
    }
    
    
    void getLeftH(vector<int> heights,vector<int> &leftH){
        int n = heights.size();
        stack<int> stk;
        for(int i=0;i<n;i++){
            if(stk.empty()){
                leftH[i] = -1;
            }else{
                while(!stk.empty() && heights[stk.top()] >= heights[i])
                    stk.pop();

                if(!stk.empty())
                    leftH[i] = stk.top();
                else
                    leftH[i] = -1;
            }
            stk.push(i);
        }
    }
    
    void getRightH(vector<int> heights,vector<int> &rightH){
        int n = heights.size();
        stack<int> stk;
        for(int i=n-1;i>=0;i--){
            if(stk.empty()){
                rightH[i] = n;
            }else{
                while(!stk.empty() && heights[stk.top()] >= heights[i])
                    stk.pop();

                if(!stk.empty())
                    rightH[i] = stk.top();
                else
                    rightH[i] = n;
            }
            stk.push(i);
        }
    }
};




















































