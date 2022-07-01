class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if(newColor==oldColor)
            return image;
        fillColor(image,sr,sc,newColor,oldColor);
        return image;
    }
    
    void fillColor(vector<vector<int>>&image,int i,int j,int newColor,int oldColor){
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j]!=oldColor)
            return;
        image[i][j]=newColor;
        fillColor(image,i,j+1,newColor,oldColor);
        fillColor(image,i-1,j,newColor,oldColor);
        fillColor(image,i,j-1,newColor,oldColor);
        fillColor(image,i+1,j,newColor,oldColor);
    }
};