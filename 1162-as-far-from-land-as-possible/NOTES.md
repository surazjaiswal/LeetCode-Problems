return ans;
}
/*
int solve(vector<vector<int>> &grid,int i,int j){
cout<<i<<" "<<j<<endl;
if(i<0 || j<0 || i>= row || j >=col)
return 0;
if(grid[i][j] == 1 || grid[i][j] == 2)
return 0;
grid[i][j] = 2;
int left = 1 + solve(grid,i,j-1);
int right = 1 + solve(grid,i,j+1);
int up = 1 + solve(grid,i-1,j);
int down = 1 + solve(grid,i+1,j);
cout<<left<<" "<<right<<" "<<up<<" "<<down<<endl;
grid[i][j] = 0;
return min({left,right,up,down});
}
*/
};
```