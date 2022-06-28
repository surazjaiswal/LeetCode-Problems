class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // here the observation same like rectangle histogram
        // if we separate each row and try to make histogram for each row as base and above rows as bars
        // we can make histogram for each row, with bars as sum of above row
        // now apply the same concept as in max rect area in histogram for each row histogram
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> mat(n,vector<int> (m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int d =  matrix[i][j] - '0';
                if(i==0)
                    mat[i][j] = d;
                else{
                    if(d!=0){
                        mat[i][j] = d + mat[i-1][j];
                    }
                }
            }
        }
        
        int ans = 0;
        for(auto it : mat){
            int area = histogram_area(it);
            ans = max(ans,area);
        }
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<mat[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return ans;
    }
    
    
    int histogram_area(vector<int> &heights){
        int n = heights.size();
        vector<int> leftH(n),rightH(n);
        getLeftH(heights,leftH);
        getRightH(heights,rightH);
        int max_area = 0;
        for(int i=0;i<n;i++){
            int width = rightH[i] - leftH[i] - 1;
            int temp_area = heights[i] * width;
            max_area = max(max_area,temp_area);
        }
        return max_area;
    }
    
    void getLeftH(vector<int> &heights,vector<int> &leftH){
        
        int n = heights.size();
        stack<int> stk;
        
        for(int i=0;i<n;i++){
            if(stk.empty()){
                leftH[i] = -1;
            }else{
                while(!stk.empty() && heights[stk.top()] >= heights[i])
                    stk.pop();
                
                if(stk.empty())
                    leftH[i] = -1;
                else
                    leftH[i] = stk.top();
            }
            stk.push(i);
        }
        
    }
    
    void getRightH(vector<int> &heights,vector<int> &rightH){
        
        int n = heights.size();
        stack<int> stk;
        
        for(int i=n-1;i>=0;i--){
            if(stk.empty()){
                rightH[i] = n;
            }else{
                while(!stk.empty() && heights[stk.top()] >= heights[i])
                    stk.pop();
                
                if(stk.empty())
                    rightH[i] = n;
                else
                    rightH[i] = stk.top();
            }
            stk.push(i);
        }
        
    }
    
    
    
};