class Solution {
public:
    int iCount=0;
    int row,col;
    // int dx[]={-1,1,0,0};
    // int dy[]={0,0,1,-1};
    
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();
        
        // int iCount=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    dfs_helper(grid,i,j);
                    iCount++;
                }
            }
        }
        return iCount;
    }
    
    void dfs_helper(vector<vector<char>>& grid,int x,int y){
        if(x<0 || y<0 || x>=row || y>=col) 
            return;
        if(grid[x][y]=='0' || grid[x][y]=='2') 
            return;
        
        grid[x][y]='2';
        
        // for(int k=0;k<4;k++){
            // dfs_helper(grid,x+dx[k],y+dy[k]);
            dfs_helper(grid,x-1,y);
            dfs_helper(grid,x+1,y);
            dfs_helper(grid,x,y+1);
            dfs_helper(grid,x,y-1);
        // }
    }
};