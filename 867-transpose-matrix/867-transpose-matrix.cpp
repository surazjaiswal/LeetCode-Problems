class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        if(row == col){
            for(int i=0;i<row;i++){
                for(int j=i;j<col;j++)
                    swap(matrix[i][j],matrix[j][i]);
            }
            return matrix;
        }
        
        vector<int> nums;
        for(int i=0;i<col;i++){
            for(int j=0;j<row;j++){
                nums.push_back(matrix[j][i]);
            }
        }
        
        int cnt=0;
        vector<vector<int>> ans;
        for(int i=0;i<col;i++){
            vector<int> vt;
            for(int j=0;j<row;j++){
                vt.push_back(nums[cnt++]);
            }
            ans.push_back(vt);
        }
        return ans;
    }
};