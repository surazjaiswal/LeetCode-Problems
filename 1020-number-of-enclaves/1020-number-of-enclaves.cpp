class Solution {
public:
    int row,col;
    int numEnclaves(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        
        int iCount = 0;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 1){
                    int cnt=0;
                    if(solve(grid,i,j,cnt)){  
                        // check for the final boolean value 
                        // if true that means there is no boundry connected to current island
                        // then return iCount else return 0
                        iCount += cnt;
                    }
                }
            }
        }
        
        return iCount;
    }
    
    bool solve(vector<vector<int>> &grid,int i,int j,int &cnt){
        if(i<0 || j<0 || i>= row || j>=col)
            return false;
        
        if(grid[i][j] == 0 || grid[i][j] == 2)
            return true;
        
        grid[i][j] = 2;
        
        int left = solve(grid,i,j-1,cnt);
        int right = solve(grid,i,j+1,cnt);
        int up = solve(grid,i-1,j,cnt);
        int down = solve(grid,i+1,j,cnt);
        
        if(left && right && up & down)
            cnt++;
        
        return (left && right && up & down);
    }
};