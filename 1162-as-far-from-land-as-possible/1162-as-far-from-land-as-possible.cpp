class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 1)
                    q.push({i,j});
            }
        }
        
        if(q.size() == row*col)
            return -1;
        
        int dist = 0;
        
        while(!q.empty()){
            dist++;
            int sz = q.size();
            while(sz--){
                auto [x, y] = q.front();
                q.pop();
                
                for(int k=0;k<4;k++){
                    int i = x + dx[k];
                    int j = y + dy[k];
                    
                    if(i >= 0 && i < row && j >= 0 && j < col && grid[i][j] == 0){
                        q.push({i,j});
                        grid[i][j] = 1;
                    }
                }
            }
        }
        return dist-1;
    }
};