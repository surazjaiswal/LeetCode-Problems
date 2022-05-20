class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        if(grid[0][0]==1 || grid[m-1][n-1]==1){
            return 0;
        }
        
        int k=0;
        while(k<n && grid[0][k]==0){
            grid[0][k]=1;
            k++;
        }
        while(k<n){
            grid[0][k++]=0;
        }
        
        k=1;
        while(k<m && grid[k][0]==0){
            grid[k][0]=1;
            k++;
        }
        while(k<m){
            grid[k++][0]=0;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                }else{
                    grid[i][j] = grid[i-1][j] + grid[i][j-1];
                }
            }
        }
        return grid[m-1][n-1];
    }
};