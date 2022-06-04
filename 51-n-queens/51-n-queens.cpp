class Solution {
public:
    
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> board(n,string(n,'.'));
        place(board,0,n);
               
        return ans;
    }
    
    void place(vector<string> &board,int row,int n){
        
        if(row == n){
            ans.push_back(board);
            return;
        }            

        for(int j=0;j<n;j++){
            bool placed = canBePlaced(board,row,j,n);
            if(placed){
                board[row][j] = 'Q';
                place(board,row+1,n);
                board[row][j] = '.';
            }
        }
        
    }
    
    bool canBePlaced(vector<string> &board,int i,int j,int n){
        // check in the row
        for(int k=0;k<n;k++){
            if(board[k][j] != '.')
                return false;
        }
        
        // check for the cols
        for(int k=0;k<n;k++){
            if(board[i][k] != '.')
                return false;
        }
        
        // diagonal check
        int x,y;
        // leftUp
        x=i,y=j;
        while(x>=0 && y>=0){
            if(board[x][y] != '.')
                return false;
            x--,y--;
        }
        
        // rightUp
        x=i,y=j;
        while(x >=0  && y<n){
            if(board[x][y] != '.')
                return false;
            x--,y++;
        }
        
        // leftDown
        x=i,y=j;
        while(x<n && y>=0){
            if(board[x][y] != '.')
                return false;
            x++,y--;
        }
        
        // rightDown
        x=i,y=j;
        while(x<n && y<n){
            if(board[x][y] != '.')
                return false;
            x++,y++;
        }
        
        return true;               
        
    }
};