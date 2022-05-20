```
class Solution {
public:
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
int m=obstacleGrid.size();
int n=obstacleGrid[0].size();
if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)
return 0;
for(int i=0;i<m;i++){
for(int j=0;j<n;j++){
if(obstacleGrid[i][j]==1)
obstacleGrid[i][j]=-1;
}
}
int k=0;
while(k<n && obstacleGrid[0][k]!=-1){
obstacleGrid[0][k]=1;
k++;
}
k=0;
while(k<m && obstacleGrid[k][0]!=-1){
obstacleGrid[0][k]=1;
k++;
}
for(int i=1;i<m;i++){
for(int j=1;j<n;j++){
if(obstacleGrid[i][j]==0){
obstacleGrid[i][j]=obstacleGrid[i][j-1]+obstacleGrid[i-1][j];
}else{
obstacleGrid[i][j]=0;
}
}
}
return obstacleGrid[m-1][n-1];
}
};
```