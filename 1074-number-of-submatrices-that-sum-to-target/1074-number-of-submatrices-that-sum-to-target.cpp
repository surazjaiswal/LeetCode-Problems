class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        // creating prefix sum for each row
        for(int i=0;i<row;i++){
            for(int j=1;j<col;j++)
                matrix[i][j] += matrix[i][j-1];
        }
        
        int ans = 0;
        unordered_map<int,int> mp;
        // calculating sum for each possible sub-matrix
        for(int colStart = 0; colStart < col; colStart++){
            for(int colEnd = colStart; colEnd < col; colEnd++){
                int csum = 0;
                mp={{0,1}};
                for(int r = 0; r < row; r++){
                    csum += matrix[r][colEnd] - (colStart ? matrix[r][colStart-1] : 0);
                    // mp[sum-target] will give number of submatrices found having sum as 'sum - target'
                    ans += mp[csum - target];
                    mp[csum]++;
                }
            }
        }
        return ans;
    }
};