class Solution {
public:
    bool hasIsland;
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int n = grid1.size();
        int m = grid1[0].size();
        
        int iCount = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j] == 1){
                    hasIsland = true; // considering current island has all land in grid1
                    solve(grid1,grid2,i,j); // traversing the island if it is true or no
                    if(hasIsland){
                        iCount++; // got all the land pieces required, add to sub island count
                    }
                }
            }
        }
        
        return iCount;
    }
    
    void solve(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j){
        
        // boundry cases
        if(i < 0 || j < 0 || i >= grid2.size() || j >= grid2[0].size())
            return;
        
        // if not land in grid 2
        if(grid2[i][j] != 1)
            return;
        
        // if no land found in grid 1 for grid 2
        if(grid1[i][j] == 0){
            hasIsland = false;
            return;
        }
        
        // marking curr piece of land as visited
        grid2[i][j] = 0;
        
        solve(grid1,grid2,i-1,j); // up
        solve(grid1,grid2,i+1,j); // down
        solve(grid1,grid2,i,j+1); // right
        solve(grid1,grid2,i,j-1); // left
        
    }
};