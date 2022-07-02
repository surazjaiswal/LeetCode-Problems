class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    if(solve(grid,i,j)){
                        ans++;    
                    }
                }
                // cout<<grid[i][j]<<" ";
            }
            // cout<<endl;
        }
        // cout<<endl;
        return ans;
    }
    
    bool solve(vector<vector<int>>& grid,int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return false;
        
        if(grid[i][j] == 1 || grid[i][j] == 2)
            return true;
        
        grid[i][j]=2;
        
        bool left = solve(grid,i,j-1);
        bool right = solve(grid,i,j+1);
        bool up = solve(grid,i-1,j);
        bool down = solve(grid,i+1,j);
        
        if(left && right && up && down)
            return true;
        
        return false;
        
    }
};