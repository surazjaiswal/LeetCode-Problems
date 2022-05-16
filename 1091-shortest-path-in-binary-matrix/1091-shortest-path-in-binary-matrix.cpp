class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(grid[0][0] || (n==1 && grid[0][0]))
            return -1;
        
        vector<int> dx = {1, 1, 0, -1, -1, -1, 0, 1}; // {-1,-1,-1,0,0,1,1,1};
        vector<int> dy = {0, 1, 1, 1, 0, -1, -1, -1}; // {-1,0,1,-1,1,-1,0,1};
        vector<vector<int>> visited(n,vector<int> (n,0));
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0]=1;
        int ans=0;
        
        while(!q.empty()){
            ans++;
            int sz = q.size();
            while(sz--){
                auto it = q.front();
                q.pop();
                int i = it.first;
                int j = it.second;

                if(i==n-1 && j==n-1)
                    return ans;

                for(int t=0;t<8;t++){
                    int x = i + dx[t];
                    int y = j + dy[t];

                    if(x >= 0 && y>=0 && x<n && y<n && grid[x][y]==0 && visited[x][y]==0){
                        visited[x][y]=1;
                        q.push({x,y});
                    }
                }
            }
        }
        
        return -1;
    }
    
    
};
