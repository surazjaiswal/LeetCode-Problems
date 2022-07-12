class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& enter) {
        int n = maze.size();
        int m = maze[0].size();
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        
        queue<pair<int,int>> q;
        vector<vector<int>> visited(n,vector<int> (m,false));
        
        q.push({enter[0],enter[1]});
        visited[enter[0]][enter[1]] = true;
        
        int move = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [i, j] = q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    
                    
                    if(x < 0 || y < 0 || x >= n || y >= m || maze[x][y] == '+'){
                        // cout<<"blocked "<<x<<" "<<y<<endl;
                        continue;
                    }
                    
                    if((x == 0 || y == 0 || x == n-1 || y == m-1) && !visited[x][y]){
                        // cout<<"exited "<<x<<" "<<y<<endl;
                        return move;
                    }
                    
                    if(!visited[x][y]){
                        // cout<<"moved "<<x<<" "<<y<<endl;
                        visited[x][y]=true;
                        q.push({x,y});
                    }
                    
                }
            }
            move++;
        }
        return -1;
    }
};



