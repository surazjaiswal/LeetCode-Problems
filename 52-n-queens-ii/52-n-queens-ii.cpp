class Solution {
public:
    int totalNQueens(int n) {
        int ans=0;
        // creating board for placing queens
        vector<vector<int>> board(n,vector<int>(n,0));
        // recursive fxn to place queens
        // passing the staring row and number of queens or size of board
        // also passing ans by reference to count number of possibilities 
        solve(board,0,n,ans); 
        
        return ans;
    }
    
    // recursive fxn to solve the n-queen problem
    void solve(vector<vector<int>> &board,int row,int n,int &ans){
        // check if we finished placing all the queens or exhusted all the rows
        // that means row will become equal n
        if(row == n){
            ans++;
            return;
        }
        
        // else we have valid row to place next queens
        // now for every col in this row 1st we check is this a valid position to place or not
        for(int col=0;col<n;col++){
            if(canBePlaced(board,row,col,n)){
                // we can safely place the queen
                board[row][col]=1;
                // now we will solve the problem for next queen , which will be placed in next row
                solve(board,row+1,n,ans);
                // here we will backtrack, that is remove the placed queen, so that we can also check for places
                board[row][col]=0;
            }
        }
    }
    
    // boolean fxn to check is queen can be placed at current position
    bool canBePlaced(vector<vector<int>> &board,int row,int col, int n){
        // for checking in the row
        for(int k=0;k<n;k++){
            if(board[k][col])
                return false;
        }
        
        // for checking in the col
        for(int k=0;k<n;k++){
            if(board[row][k])
                return false;
        }
        
        // checking in diagonal
        int x=row,y=col;
        // left upper diagonal
        while(x>=0 && y>=0){
            if(board[x][y])
                return false;
            x--,y--;
        }
        
        x=row,y=col;
        // right upper diagonal
        while(x>=0 && y<n){
            if(board[x][y])
                return false;
            x--,y++;
        }
        
         x=row,y=col;
        // left lower diagonal
        while(x<n&& y>=0){
            if(board[x][y])
                return false;
            x++,y--;
        }
        
         x=row,y=col;
        // right lower diagonal
        while(x<n && y<n){
            if(board[x][y])
                return false;
            x++,y++;
        }
        
        // here all cases has been satisfied, queen can be placed at this position
        return true;
    }
};