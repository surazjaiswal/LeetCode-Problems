class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<pair<int,int>> land1, land2;
        
        int iCount = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    iCount++;
                    if(iCount == 1){
                        dfs_helper(grid,i,j,land1);
                    }
                    if(iCount == 2){
                        dfs_helper(grid,i,j,land2);
                    }
                }
            }
        }
        
        int ans = INT_MAX;
        for(int i=0;i<land1.size();i++){
            for(int j=0;j<land2.size();j++){
                int dist = abs(land1[i].first - land2[j].first) + abs(land1[i].second - land2[j].second) - 1;
                ans = min(ans, dist);
            }
        }
        
        return ans;
    }
    
    
    void dfs_helper(vector<vector<int>>& grid, int i,int j, vector<pair<int,int>> & vt){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == 0)
            return;
                
        grid[i][j] = 0;
        
        vt.push_back({i,j});
        
        dfs_helper(grid,i,j+1,vt);
        dfs_helper(grid,i+1,j,vt);
        dfs_helper(grid,i,j-1,vt);
        dfs_helper(grid,i-1,j,vt);
            
    }
};