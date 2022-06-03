class NumMatrix {
public:
    vector<vector<int>> mat_sum;
    NumMatrix(vector<vector<int>>& matrix) {
        mat_sum = matrix;
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        for(int i=1;i<row;i++)
            mat_sum[i][0] += mat_sum[i-1][0];
        
        for(int j=1;j<col;j++)
            mat_sum[0][j] += mat_sum[0][j-1];

        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                mat_sum[i][j] += mat_sum[i-1][j] + mat_sum[i][j-1] - mat_sum[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        
        if(row1 == 0 && col1 == 0)
            sum =  mat_sum[row2][col2];
        
        else if(row1 == 0 && col1 != 0)
            sum = mat_sum[row2][col2] - mat_sum[row2][col1-1];
        
        else if(row1 != 0 && col1 == 0)
            sum = mat_sum[row2][col2] - mat_sum[row1-1][col2];
        
        else
        {
            sum =     mat_sum[row2][col2] 
                    - mat_sum[row1-1][col2]  
                    - mat_sum[row2][col1-1]
                    + mat_sum[row1-1][col1-1];
        }
        
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */