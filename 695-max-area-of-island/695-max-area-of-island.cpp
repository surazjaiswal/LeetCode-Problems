class Solution {
public:
    int row,col;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        row=grid.size();
        col=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    int count=0;
                    getSize(grid,i,j,count);
                    ans=max(ans,count);
                }
            }
        }
        return ans;
    }
    
    void getSize(vector<vector<int>>& grid,int i,int j,int &count){
        if(i<0 || j<0 || i>=row || j>=col || grid[i][j]!=1)
            return;
        grid[i][j]=2;
        count++;
        getSize(grid,i,j+1,count);
        getSize(grid,i-1,j,count);
        getSize(grid,i,j-1,count);
        getSize(grid,i+1,j,count);
    }
};