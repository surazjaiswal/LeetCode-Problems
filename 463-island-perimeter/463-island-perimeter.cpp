class Solution {
public:
    int row,col;
    int islandPerimeter(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
                
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                   return getPerimeter(i,j,grid);
                }
            }
        }
        return 0;
    }
    int getPerimeter(int x,int y,vector<vector<int>>& grid){
        if(x<0 || y<0 || x>=row || y>=col || grid[x][y]==0){
            return 1;
        }
        
        if(grid[x][y]==2)
            return 0;
        
        grid[x][y]=2;
        
        int a = getPerimeter(x,y+1,grid);
        int b = getPerimeter(x-1,y,grid);
        int c = getPerimeter(x,y-1,grid);
        int d = getPerimeter(x+1,y,grid);
        
        return (a+b+c+d);
    }
};
